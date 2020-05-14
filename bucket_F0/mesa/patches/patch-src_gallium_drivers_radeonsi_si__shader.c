--- src/gallium/drivers/radeonsi/si_shader.c.orig	2020-05-14 16:50:14 UTC
+++ src/gallium/drivers/radeonsi/si_shader.c
@@ -22,6 +22,10 @@
  * USE OR OTHER DEALINGS IN THE SOFTWARE.
  */
 
+#ifdef __sun__
+#include <alloca.h> /* for alloca */
+#endif
+
 #include "util/u_memory.h"
 #include "tgsi/tgsi_strings.h"
 #include "tgsi/tgsi_from_mesa.h"
