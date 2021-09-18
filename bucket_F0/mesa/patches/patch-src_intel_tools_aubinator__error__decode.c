# expose getline in FreeBSD's stdio.h
#
--- src/intel/tools/aubinator_error_decode.c.orig	2021-09-08 21:22:01 UTC
+++ src/intel/tools/aubinator_error_decode.c
@@ -22,6 +22,9 @@
  *
  */
 
+#ifdef __FreeBSD__
+#define _WITH_GETLINE
+#endif
 #include <stdbool.h>
 #include <stdio.h>
 #include <stdlib.h>
