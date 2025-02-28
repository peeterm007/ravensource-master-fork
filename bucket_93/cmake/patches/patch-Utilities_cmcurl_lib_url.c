--- Utilities/cmcurl/lib/url.c.orig	2022-11-30 13:57:03 UTC
+++ Utilities/cmcurl/lib/url.c
@@ -647,6 +647,10 @@ CURLcode Curl_init_userdefined(struct Cu
     CURL_HTTP_VERSION_1_1
 #endif
     ;
+#if defined(__FreeBSD__)
+  /* different handling of signals and threads */
+  set->no_signal = TRUE;
+#endif
   Curl_http2_init_userset(set);
   return result;
 }
