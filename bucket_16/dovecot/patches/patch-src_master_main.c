--- src/master/main.c.orig	2019-03-25 08:43:27 UTC
+++ src/master/main.c
@@ -862,6 +862,8 @@ int main(int argc, char *argv[])
 		i_fatal("dup2(dev_null_fd) failed: %m");
 	if (!foreground && dup2(dev_null_fd, STDOUT_FILENO) < 0)
 		i_fatal("dup2(dev_null_fd) failed: %m");
+	if (!foreground && dup2(dev_null_fd, STDERR_FILENO) < 0)
+		i_fatal("dup2(dev_null_fd) failed: %m");
 
 	pidfile_path =
 		i_strconcat(set->base_dir, "/"MASTER_PID_FILE_NAME, NULL);
