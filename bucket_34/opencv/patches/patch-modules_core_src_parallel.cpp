--- modules/core/src/parallel.cpp.orig	2020-07-17 22:43:40 UTC
+++ modules/core/src/parallel.cpp
@@ -54,6 +54,7 @@
 #endif
 
 #if defined __linux__ || defined __APPLE__ || defined __GLIBC__ \
+    || defined __DragonFly__ \
     || defined __HAIKU__ || defined __EMSCRIPTEN__ || defined __FreeBSD__
     #include <unistd.h>
     #include <stdio.h>
