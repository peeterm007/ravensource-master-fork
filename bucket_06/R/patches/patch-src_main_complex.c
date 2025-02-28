--- src/main/complex.c.orig	2022-09-29 22:15:01 UTC
+++ src/main/complex.c
@@ -139,7 +139,7 @@ static double complex mycpow (double com
     } else if (yi == 0.0 && yr == (k = (int) yr) && abs(k) <= 65536)
 	Z = R_cpow_n(X, k);
     else
-#ifdef HAVE_CPOW
+#if defined(HAVE_CPOW) && !defined(__FreeBSD__)
 	Z = cpow(X, Y);
 #else
     {
@@ -394,7 +394,7 @@ void attribute_hidden z_prec_r(Rcomplex
    Currently (Feb 2011) they are used on FreeBSD.
 */
 
-#ifndef HAVE_CLOG
+#if !defined(HAVE_CLOG) || defined(__FreeBSD__)
 #define clog R_clog
 /* FIXME: maybe add full IEC60559 support */
 static double complex clog(double complex x)
