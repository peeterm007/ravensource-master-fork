--- src/third_party/httplib.h.orig	2022-11-21 18:53:32 UTC
+++ src/third_party/httplib.h
@@ -168,7 +168,9 @@ using socket_t = SOCKET;
 #else // not _WIN32
 
 #include <arpa/inet.h>
+#ifndef __sun
 #include <ifaddrs.h>
+#endif
 #include <net/if.h>
 #include <netdb.h>
 #include <netinet/in.h>
