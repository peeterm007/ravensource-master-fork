--- src/lib-master/test-event-stats.c.orig	2019-03-25 08:43:27 UTC
+++ src/lib-master/test-event-stats.c
@@ -12,6 +12,7 @@
 #include "stats-client.h"
 #include "test-common.h"
 #include <fcntl.h>
+#include <signal.h>
 #include <unistd.h>
 #include <signal.h>
 #include <sys/socket.h>
