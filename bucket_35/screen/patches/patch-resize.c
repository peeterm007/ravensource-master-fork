--- resize.c.orig	2022-01-28 14:06:02 UTC
+++ resize.c
@@ -683,6 +683,17 @@ int wi, he, hi;
       he = MAXWIDTH;
     }
 
+  if (wi > 1000)
+    {
+      Msg(0, "Window width too large, truncated");
+      wi = 1000;
+    }
+  if (he > 1000)
+    {
+      Msg(0, "Window height too large, truncated");
+      he = 1000;
+    }
+
   if (p->w_width == wi && p->w_height == he && p->w_histheight == hi)
     {
       debug("ChangeWindowSize: No change.\n");
