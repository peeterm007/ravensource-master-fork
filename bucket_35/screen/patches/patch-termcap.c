--- termcap.c.orig	2022-01-28 14:06:02 UTC
+++ termcap.c
@@ -361,11 +361,7 @@ int he;
   if (D_CG0)
     {
       if (D_CS0 == 0)
-#ifdef TERMINFO
-        D_CS0 = "\033(%p1%c";
-#else
-        D_CS0 = "\033(%.";
-#endif
+	D_CS0 = "\033(%p1%c"; /* Old ncurses can't handle %. */
       if (D_CE0 == 0)
         D_CE0 = "\033(B";
       D_AC = 0;
