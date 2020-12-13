Zero-overhead lozalization is easy:
#ifndef string_header
#define string_header "standard.h" //english strings
#endif
the software would then #include string_header
or override it with makefile/compile flag
to add a translation compile with e.g. gcc -Dstring_header="lang.h"
there is no need to create different source files,entire
"translation packages" or any xML templates.
-----------
standard.h would contain defines for each string str[name]
#define stredit "Edit"
lang.h would contain
#define stredit "translated string"
lang.h could be a copy of standard.h with partial localization(replacing
only the translated parts, as required )
