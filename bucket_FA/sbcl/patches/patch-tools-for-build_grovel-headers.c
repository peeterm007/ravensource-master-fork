--- tools-for-build/grovel-headers.c.orig	2019-11-26 20:35:11 UTC
+++ tools-for-build/grovel-headers.c
@@ -43,7 +43,11 @@
   #include <termios.h>
 #else
 # ifndef LISP_FEATURE_HAIKU
+#  ifdef __DragonFly__
+#  include <termios.h>
+#  else
 #  include <sys/termios.h>
+#  endif
 # endif
   #include <langinfo.h>
 #endif
