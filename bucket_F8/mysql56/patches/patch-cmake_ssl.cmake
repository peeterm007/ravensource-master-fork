--- cmake/ssl.cmake.orig	2018-09-10 10:17:55 UTC
+++ cmake/ssl.cmake
@@ -176,7 +176,7 @@ MACRO (MYSQL_CHECK_SSL)
     IF(OPENSSL_INCLUDE_DIR AND
        OPENSSL_LIBRARY   AND
        CRYPTO_LIBRARY      AND
-       OPENSSL_MAJOR_VERSION STREQUAL "1"
+       OPENSSL_MAJOR_VERSION VERSION_GREATER_EQUAL "1"
       )
       SET(OPENSSL_FOUND TRUE)
     ELSE()
