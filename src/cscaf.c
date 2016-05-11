#include <ctype.h>	/* toupper */
#include "cscaf.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
		EXIT_ON_FAILURE("missing project name");

	char dir[MAXPATHLEN];
	char contents[MAX_FILE_SIZE];

	const char *const raw_name = argv[1];
	const char *const cap_name = capitalize_string(raw_name);

	const char *const name_map[] = {
		[project] = raw_name,
		[PROJECT] = cap_name
	};

	char *base = make_root_dir(&dir[0], raw_name);

	char *const root = base;

	strcpy(root, "LICENSE");
	write_contents_to_file(dir, LICENSE);

	strcpy(root, "Makefile");
	write_contents_to_file(dir, OUTER_MAKE);

	build_contents(&contents[0],
		       &README_SEGS[0],
		       &README_FILL_MAP[0],
		       &name_map[0],
		       README_FILL_COUNT);

	write_contents_to_file(dir, &contents[0]);

	base = stpcpy(root, "src");
	HANDLE_MKDIR_DEFAULT(dir);

	return 0;
}

inline void build_contents(char *restrict contents,
			   const char *const *restrict segs,
			   const enum ProjectNameCase *restrict fill_map,
			   const char *const *restrict name_map,
			   const size_t fill_count)
{
	size_t i = 0ul;

	do {
		contents = extend_string(contents, segs[i]);
		contents = extend_string(contents, name_map[ fill_map[i] ]);

		++i;

	} while (i < fill_count);

	contents = extend_string(contents, segs[fill_count]);

	*contents = '\0';
}


char *make_root_dir(char *restrict dir,
		    const char *restrict name)
{
	char *cwd;
	char *base;

	HANDLE_GETCWD(cwd);

	base = extend_string(dir, cwd);

	PUT_SLASH(base);

	base = stpcpy(base, name);

	HANDLE_MKDIR_DEFAULT(dir);

	PUT_SLASH(base);

	return base;
}


inline void write_contents_to_file(const char *restrict filename,
				   const char *restrict string)
{
	FILE *file;
	HANDLE_FOPEN(file, filename, "w");

	fputs(string, file);

	fclose(file);
}


inline char *extend_string(char *restrict buffer,
			   const char *restrict extend)
{
	while (*extend != '\0') {
		*buffer = *extend;
		++buffer;
		++extend;
	}

	return buffer;
}

inline char *capitalize_string(const char *restrict string)
{
	char *restrict cap_string;

	const size_t length = strlen(string);

	HANDLE_MALLOC(cap_string,
		      sizeof(char) * (length + 1ul));

	for (size_t i = 0ul; i < length; ++i)
		cap_string[i] = (char) toupper((int) string[i]);

	cap_string[length] = '\0';

	return cap_string;
}
