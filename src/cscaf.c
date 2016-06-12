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
	char cwd[MAXPATHLEN];
	char *restrict base;

	HANDLE_GETCWD(&cwd[0], sizeof(cwd));

	base = put_string(path, &cwd[0]);

	PUT_FILE_DELIM(base);

	base = stpcpy(base, name);

	HANDLE_MKDIR_DEFAULT(path);

	PUT_FILE_DELIM(base);

	return base;
}
