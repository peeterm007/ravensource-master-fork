--- lib/mount_bsd.c.orig	2022-09-08 10:02:45 UTC
+++ lib/mount_bsd.c
@@ -19,7 +19,9 @@
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <sys/sysctl.h>
+#if !defined(__NetBSD__)
 #include <sys/user.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
