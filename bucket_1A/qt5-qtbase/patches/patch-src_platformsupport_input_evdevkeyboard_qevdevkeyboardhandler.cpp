--- src/platformsupport/input/evdevkeyboard/qevdevkeyboardhandler.cpp.orig	2022-06-24 10:42:02 UTC
+++ src/platformsupport/input/evdevkeyboard/qevdevkeyboardhandler.cpp
@@ -52,11 +52,7 @@
 #include <QtGui/private/qguiapplication_p.h>
 #include <QtGui/private/qinputdevicemanager_p.h>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 
 #ifndef input_event_sec
 #define input_event_sec time.tv_sec
