--- src/gprlib.adb.orig	2022-09-22 17:08:57 UTC
+++ src/gprlib.adb
@@ -809,9 +809,6 @@ procedure Gprlib is
 
       for Dir of Imported_Library_Directories loop
          Library_Switches_Table.Append ("-L" & Dir);
-         if not Path_Option.Is_Empty then
-            Add_Rpath (Dir);
-         end if;
       end loop;
 
       for Libname of Imported_Library_Names loop
@@ -913,12 +910,6 @@ procedure Gprlib is
               Shared_Lib_Suffix.all);
       end if;
 
-      if not Path_Option.Is_Empty then
-         for Path of Library_Rpath_Options_Table loop
-            Add_Rpath (Path);
-         end loop;
-      end if;
-
       if not Path_Option.Is_Empty and then not Rpath.Is_Empty then
          if Separate_Run_Path_Options then
             for J in 1 .. Rpath.Last_Index loop
@@ -1455,7 +1446,7 @@ procedure Gprlib is
             end if;
 
          elsif Partial_Linker_Path = null then
-            Fail_Program (null, "unknown object file """ & Opt & """");
+            Put_Line ("WARNING: unknown object '" & Opt & "'");
          else
             Trailing_PL_Options.Append (Opt);
          end if;
@@ -2219,8 +2210,8 @@ procedure Gprlib is
 
                      Free (Libgnat);
                      Free (Libgnarl);
-                     Libgnat  := new String'("-lgnat-" & Line (6 .. Last));
-                     Libgnarl := new String'("-lgnarl-" & Line (6 .. Last));
+                     Libgnat  := new String'("-lgnat-" & Line (6 .. 7));
+                     Libgnarl := new String'("-lgnarl-" & Line (6 .. 7));
                   end if;
 
                else
