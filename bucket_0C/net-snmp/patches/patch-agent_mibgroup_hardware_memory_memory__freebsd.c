--- agent/mibgroup/hardware/memory/memory_freebsd.c.orig	2022-07-13 21:14:14 UTC
+++ agent/mibgroup/hardware/memory/memory_freebsd.c
@@ -164,7 +164,7 @@ int netsnmp_mem_arch_load( netsnmp_cache
         if (!mem->descr)
              mem->descr = strdup("Cached memory");
         mem->units = pagesize;
-        mem->size  = cache_count;
+        mem->size  = cache_count + inact_count;
         mem->free  = 0;
     }
 
