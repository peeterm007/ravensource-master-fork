--- modules/videoio/src/cap_v4l.cpp.orig	2021-07-05 12:03:22 UTC
+++ modules/videoio/src/cap_v4l.cpp
@@ -228,7 +228,9 @@ make & enjoy!
 #include <poll.h>
 
 #ifdef HAVE_CAMV4L2
+#ifdef __linux__
 #include <asm/types.h>          /* for videodev2.h */
+#endif
 #include <linux/videodev2.h>
 #endif
 
