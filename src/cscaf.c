#include <ctype.h>	/* toupper */
#include "cscaf.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
		EXIT_ON_FAILURE("missing project name");

	char path[MAXPATHLEN];
	char contents[MAX_FILE_SIZE];

	char *base;
	char *basename;

	const char *const raw_name = argv[1];
	const char *const cap_name = capitalize_string(raw_name);

	const char *const name_map[] = {
		[project] = raw_name,
		[PROJECT] = cap_name
	};

	/* ./project */
	char *const root = make_root_dir(path, raw_name);

	/* ./project/LICENSE */
	strcpy(root, "LICENSE");
	write_contents_to_file(path, LICENSE);

	/* ./project/Makefile */
	strcpy(root, "Makefile");
	write_contents_to_file(path, OUTER_MAKE);

	/* ./project/README.md */
	strcpy(root, "README.md");
	build_contents(contents,
		       name_map,
		       README_SEGS,
		       README_FILL_MAP,
		       README_FILL_COUNT);
	write_contents_to_file(path, contents);

	/* ./project/bin */
	strcpy(root, "bin");
	HANDLE_MKDIR_DEFAULT(path);

	/* ./project/obj */
	strcpy(root, "obj");
	HANDLE_MKDIR_DEFAULT(path);

	/* ./project/src */
	base = stpcpy(root, "src");
	HANDLE_MKDIR_DEFAULT(path);
	PUT_SLASH(base);

	/* ./project/src/project.c */
	basename = extend_string(base, raw_name);
	strcpy(basename, ".c");
	build_contents(contents,
		       name_map,
		       SOURCE_SEGS,
		       SOURCE_FILL_MAP,
		       SOURCE_FILL_COUNT);
	write_contents_to_file(path, contents);

	/* ./project/src/project.h */
	strcpy(basename, ".h");
	build_contents(contents,
		       name_map,
		       HEADER_SEGS,
		       HEADER_FILL_MAP,
		       HEADER_FILL_COUNT);
	write_contents_to_file(path, contents);

	/* ./project/src/Makefile */
	strcpy(base, "Makefile");
	build_contents(contents,
		       name_map,
		       INNER_MAKE_SEGS,
		       INNER_MAKE_FILL_MAP,
		       INNER_MAKE_FILL_COUNT);
	write_contents_to_file(path, contents);

	/* ./project/src/test */
	base = stpcpy(base, "test");
	HANDLE_MKDIR_DEFAULT(path);


	return 0;
}

inline void build_contents(char *restrict contents,
			   const char *const *restrict name_map,
			   const char *const *restrict segs,
			   const enum ProjectNameCase *restrict fill_map,
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
