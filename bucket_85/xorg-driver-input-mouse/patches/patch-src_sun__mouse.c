$NetBSD: patch-src_sun__mouse.c,v 1.2 2016/11/17 08:06:52 wiz Exp $

rearrange includes to fix build on OmniOS. Include unistd.h for ioctl(2).

--- src/sun_mouse.c.orig	2022-11-02 02:44:34 UTC
+++ src/sun_mouse.c
@@ -55,6 +55,10 @@
 #include <xorg-config.h>
 #endif
 
+#include <unistd.h> /* for ioctl(2) */
+#include <sys/stropts.h>
+#include <sys/vuid_event.h>
+#include <sys/msio.h>
 #include "xorg-server.h"
 #include "xf86.h"
 #include "xf86_OSlib.h"
@@ -62,9 +66,6 @@
 #include "xisb.h"
 #include "mipointer.h"
 #include "xf86Crtc.h"
-#include <sys/stropts.h>
-#include <sys/vuid_event.h>
-#include <sys/msio.h>
 
 /* Wheel mouse support in VUID drivers in Solaris 9 updates & Solaris 10 */
 #ifdef WHEEL_DEVID /* Defined in vuid_event.h if VUID wheel support present */
