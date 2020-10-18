--- 3rdparty/ittnotify/src/ittnotify/ittnotify_config.h.orig	2020-10-11 21:26:07 UTC
+++ 3rdparty/ittnotify/src/ittnotify/ittnotify_config.h
@@ -80,7 +80,7 @@
 #    define ITT_OS ITT_OS_WIN
 #  elif defined( __APPLE__ ) && defined( __MACH__ )
 #    define ITT_OS ITT_OS_MAC
-#  elif defined( __FreeBSD__ )
+#  elif defined( __FreeBSD__ ) || defined __DragonFly__
 #    define ITT_OS ITT_OS_FREEBSD
 #  else
 #    define ITT_OS ITT_OS_LINUX
