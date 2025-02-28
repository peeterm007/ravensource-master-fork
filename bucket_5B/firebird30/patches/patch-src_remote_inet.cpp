--- src/remote/inet.cpp.orig	2020-10-12 00:02:22 UTC
+++ src/remote/inet.cpp
@@ -962,7 +962,7 @@ rem_port* INET_connect(const TEXT* name,
 		gai_hints.ai_family = ((host.hasData() || !ipv6) ? AF_UNSPEC : AF_INET6);
 	gai_hints.ai_socktype = SOCK_STREAM;
 
-#if !defined(WIN_NT) && !defined(__clang__)
+#if !defined(WIN_NT) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 	gai_hints.ai_protocol = SOL_TCP;
 #else
 	gai_hints.ai_protocol = IPPROTO_TCP;
@@ -1177,6 +1177,12 @@ static rem_port* listener_socket(rem_por
 
 	inet_ports->registerPort(port);
 
+	char *parent_pid;
+	if (parent_pid = getenv("FB_SIGNAL_PROCESS"))
+	{
+		kill(atoi(parent_pid), SIGUSR1);
+	}
+
 	if (flag & SRVR_multi_client)
 	{
 		// Prevent the generation of dummy keepalive packets on the connect port.
