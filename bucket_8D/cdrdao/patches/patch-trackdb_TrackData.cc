--- trackdb/TrackData.cc.orig	2018-05-15 13:30:52 UTC
+++ trackdb/TrackData.cc
@@ -642,7 +642,7 @@ int TrackData::waveLength(const char *fi
   char magic[4];
   long headerLen = 0;
   long len;
-  short waveFormat;
+  unsigned short waveFormat;
   short waveChannels;
   long waveRate;
   short waveBits;
@@ -715,7 +715,7 @@ int TrackData::waveLength(const char *fi
 
   waveFormat = readShort(fp);
 
-  if (waveFormat != 1) {
+  if (waveFormat != 1 && waveFormat != 0xfffe) {
     // not PCM format
     log_message(-2, "%s: not in PCM format.", filename);
     fclose(fp);
@@ -749,7 +749,21 @@ int TrackData::waveLength(const char *fi
     return 2;
   }
   
-  len -= 16;
+  if (waveFormat == 1)
+    len -= 16;
+  else {
+    readShort(fp); // cbsize
+    readShort(fp); // validbits
+    readLong(fp); // channelmask
+    waveFormat = readShort(fp); // subformat
+    if (waveFormat != 1) {
+      // not PCM format
+      log_message(-2, "%s: not in PCM format.", filename);
+      fclose(fp);
+      return 2;
+    }
+    len -= 26;
+  }
 
   // skip chunk data
   if (fseek(fp, len, SEEK_CUR) != 0) {
