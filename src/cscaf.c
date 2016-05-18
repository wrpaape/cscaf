#include "cscaf.h"

extern inline void build_contents(char *restrict contents,
				  const char *const *restrict name_map,
				  const char *const *restrict segs,
				  const enum ProjectNameCase *restrict fill_map,
				  const size_t fill_count);

extern inline void write_contents_to_file(const char *restrict filename,
					  const char *restrict string);

char *make_root_dir(char *restrict path,
		    const char *restrict name)
{
	char *cwd;
	char *base;

	HANDLE_GETCWD(cwd);

	base = extend_string(path, cwd);

	PUT_SLASH(base);

	base = stpcpy(base, name);

	HANDLE_MKDIR_DEFAULT(path);

	PUT_SLASH(base);

	return base;
}
