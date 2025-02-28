--- hdrline.c.orig	2022-05-11 16:57:07 UTC
+++ hdrline.c
@@ -248,6 +248,89 @@ static char *apply_subject_mods (ENVELOP
  * %Y = `x-label:' field (if present, tree unfolded, and != parent's x-label)
  * %Z = status flags	*/
 
+static void
+format_smartdate( char *buf, size_t max, struct tm *tm, smartdate_type type )
+{
+    char *strftime_fmt = NULL;
+
+    switch( type ) {
+        case FUTURE:        /* Date in the future */
+            strftime_fmt = "%d%h%y!";
+            break;
+        case SMARTTIME:     /* Today */
+            strftime_fmt = "%I:%M %p";
+            break;
+        case YESTERDAY:     /* Yesterday */
+            strncpy( buf, "Yesterday", max );
+            break;
+        case WEEKDAY:       /* Within the last 7 days */
+            strftime_fmt = "%A";
+            break;
+        case STANDARD:      /* Within the last six months */
+            strftime_fmt = "%h %d";
+            break;
+        case ANCIENT:       /* Older than 6 months */
+            strftime_fmt = "%h %Y";
+            break;
+    }
+
+    if( strftime_fmt != NULL ) {
+        strftime( buf, max, strftime_fmt, tm );
+    }
+}
+
+static void
+smartdate( char *buf, size_t max, struct tm *tm )
+{
+    smartdate_type type = 0;
+
+    struct tm now;
+
+    time_t sse = mktime( tm );   /* Seconds since epoch */
+    time_t sse_now = time(NULL); /* Seconds since epoch until now */
+
+    int dse = 0;            /* Days since epoch */
+    int dse_now = 0;        /* Days since epoch until today */
+
+    /* Calculate the number of days since epoch */
+    dse = sse / (60*60*24);
+    dse_now = sse_now / (60*60*24);
+
+    /* Default display type */
+    type = STANDARD;
+
+    /* Check if the date is in the future */
+    if( dse > dse_now ) {
+        type = FUTURE;
+    }
+    else {
+        int diff = dse_now - dse;
+        if( diff == 0 ) type = SMARTTIME;
+        else if( diff == 1 ) type = YESTERDAY;
+        else if( diff < 7 ) type = WEEKDAY;
+        else if( diff > 215 ) type = ANCIENT;  /* Surely older than six
+                                                  months */
+        else if( diff > 180 ) {
+            /*
+             * Slightly heavy calculation to check if the date is more
+             * than six months in the past.  This calculation uses
+             * calendar months and not the exact number of days.  So,
+             * January 31, 2003 would be considered more than six months
+             * old whether today's date is August 1 or August 31, 2003
+             */
+            int monthdiff;
+            localtime_r( &sse_now, &now );
+            monthdiff = ( now.tm_mon - tm->tm_mon )
+                + ( ( now.tm_year - tm->tm_year ) * 12 );
+            if( monthdiff > 6 ) {
+                type = ANCIENT;
+            }
+        }
+    }
+
+    format_smartdate( buf, max, tm, type );
+}
+
 static const char *
 hdr_format_str (char *dest,
 		size_t destlen,
@@ -344,6 +427,53 @@ hdr_format_str (char *dest,
       const char *cp;
       struct tm *tm;
       time_t T;
+	int i = 0, invert = 0;
+
+	if (optional && (op == '[' || op == '(')) {
+	  char *is;
+	  T = time(NULL);
+	  T -= (op == '(') ? hdr->received : hdr->date_sent;
+
+	  is = (char *)prefix;
+	  if( *is == '>' ) {
+	    invert = 1;
+	    ++is;
+	  }
+
+	  while( *is && *is != '?' ) {
+	    int t = strtol (is, &is, 10);
+	    switch (*(is++)) {
+	      case '?':
+		break;
+	      case 'y':
+		t *= 365 * 24 * 60 * 60;
+		break;
+	      case 'M':
+		t *= 30 * 24 * 60 * 60;
+		break;
+	      case 'w':
+		t *= 7 * 24 * 60 * 60;
+		break;
+	      case 'd':
+		t *= 24 * 60 * 60;
+		break;
+	      case 'h':
+		t *= 60 * 60;
+		break;
+	      case 'm':
+		t *= 60;
+		break;
+	    }
+	    i += t;
+	  }
+
+	  if (i < 0)
+	    i *= -1;
+
+	  if( (T > i || T < -1*i) ^ invert )
+	    optional = 0;
+	  break;
+	}
 
       p = dest;
 
@@ -421,7 +551,13 @@ hdr_format_str (char *dest,
 
       if (!do_locales)
         setlocale (LC_TIME, "C");
-      strftime (buf2, sizeof (buf2), dest, tm);
+		/* Identify the non-strftime smartdate pattern (%@) */
+		if( strncmp( dest, "%@", 2 ) == 0 ) {
+			smartdate( buf2, sizeof( buf2 ), tm );
+		}
+		else {
+			strftime (buf2, sizeof (buf2), dest, tm);
+		}
       if (!do_locales)
         setlocale (LC_TIME, "");
 
