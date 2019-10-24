--- src/util/u_thread.h.orig	2019-10-21 16:53:58 UTC
+++ src/util/u_thread.h
@@ -34,6 +34,13 @@
 
 #ifdef HAVE_PTHREAD
 #include <signal.h>
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#include <pthread_np.h>
+# ifndef __DragonFly__
+#  define cpu_set_t cpuset_t
+# endif
+#undef ALIGN /* Avoid conflict on FreeBSD in main/macros.h */
+#endif
 #endif
 
 static inline thrd_t u_thread_create(int (*routine)(void *), void *param)
@@ -61,7 +68,15 @@ static inline thrd_t u_thread_create(int
 static inline void u_thread_setname( const char *name )
 {
 #if defined(HAVE_PTHREAD)
+#  if defined (__sun)
+   (void)name;
+#  elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+   pthread_set_name_np(pthread_self(), name);
+#  elif defined(__NetBSD__)
+   pthread_setname_np(pthread_self(), "%s", (void*)name);
+#  else
    pthread_setname_np(pthread_self(), name);
+#  endif
 #endif
    (void)name;
 }
@@ -131,7 +146,7 @@ util_get_L3_for_pinned_thread(thrd_t thr
 static inline int64_t
 u_thread_get_time_nano(thrd_t thread)
 {
-#if defined(__linux__) && defined(HAVE_PTHREAD)
+#if defined(HAVE_PTHREAD) && !defined(__sun)
    struct timespec ts;
    clockid_t cid;
 
