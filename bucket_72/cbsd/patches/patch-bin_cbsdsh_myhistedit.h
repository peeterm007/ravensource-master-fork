--- bin/cbsdsh/myhistedit.h.orig	2022-12-06 12:39:21 UTC
+++ bin/cbsdsh/myhistedit.h
@@ -32,15 +32,7 @@
  * $FreeBSD: head/bin/sh/myhistedit.h 326025 2017-11-20 19:49:47Z pfg $
  */
 
-#ifdef CBSD
-#ifdef __DragonFly__
 #include <histedit.h>
-#else
-#include "/usr/include/histedit.h"
-#endif
-#else
-#include <histedit.h>
-#endif
 
 extern History *hist;
 extern EditLine *el;
