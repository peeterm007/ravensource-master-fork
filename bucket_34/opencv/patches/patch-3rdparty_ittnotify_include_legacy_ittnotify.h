--- 3rdparty/ittnotify/include/legacy/ittnotify.h.orig	2022-12-28 14:31:52 UTC
+++ 3rdparty/ittnotify/include/legacy/ittnotify.h
@@ -85,7 +85,7 @@
 #    define ITT_OS ITT_OS_WIN
 #  elif defined( __APPLE__ ) && defined( __MACH__ )
 #    define ITT_OS ITT_OS_MAC
-#  elif defined( __FreeBSD__ )
+#  elif defined( __FreeBSD__ ) || defined __DragonFly__
 #    define ITT_OS ITT_OS_FREEBSD
 #  else
 #    define ITT_OS ITT_OS_LINUX
