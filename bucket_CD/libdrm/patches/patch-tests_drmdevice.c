--- tests/drmdevice.c.orig	2020-05-26 20:37:16 UTC
+++ tests/drmdevice.c
@@ -31,6 +31,9 @@
 #include <unistd.h>
 #include <xf86drm.h>
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
 
 static void
 print_device_info(drmDevicePtr device, int i, bool print_revision)
