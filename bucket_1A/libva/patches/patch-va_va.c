--- va/va.c.orig	2020-10-26 01:25:27 UTC
+++ va/va.c
@@ -451,7 +451,7 @@ static VAStatus va_openDriver(VADisplay
         }
 
         va_infoMessage(dpy, "Trying to open %s\n", driver_path);
-#ifndef ANDROID
+#ifdef RTLD_NODELETE
         handle = dlopen( driver_path, RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE );
 #else
         handle = dlopen( driver_path, RTLD_NOW| RTLD_GLOBAL);
