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
	const char *const cap_name = capitalized_string(raw_name);

	const char *const name_map[] = {
		[project] = raw_name,
		[PROJECT] = cap_name
	};

	/* ./project */
	char *const root = make_root_dir(path, raw_name);

	/* ./project/LICENSE */
	strcpy(root, "LICENSE");
	filename_write_all(path, LICENSE);

	/* ./project/Makefile */
	strcpy(root, "Makefile");
	filename_write_all(path, OUTER_MAKE);

	/* ./project/README.md */
	strcpy(root, "README.md");
	build_contents(contents,
		       name_map,
		       README_TEMPLATE,
		       README_FILL_MAP,
		       README_FILL_COUNT);
	filename_write_all(path, contents);

	/* ./project/bin */
	strcpy(root, "bin");
	HANDLE_MKDIR_DEFAULT(path);

	/* ./project/obj */
	strcpy(root, "obj");
	HANDLE_MKDIR_DEFAULT(path);

	/* ./project/shared */
	strcpy(root, "shared");
	HANDLE_MKDIR_DEFAULT(path);

	/* ./project/static */
	strcpy(root, "static");
	HANDLE_MKDIR_DEFAULT(path);

	/* ./project/src */
	base = stpcpy(root, "src");
	HANDLE_MKDIR_DEFAULT(path);
	PUT_FILE_DELIM(base);

	/* ./project/src/project.c */
	basename = put_string(base, raw_name);
	strcpy(basename, ".c");
	build_contents(contents,
		       name_map,
		       SOURCE_TEMPLATE,
		       SOURCE_FILL_MAP,
		       SOURCE_FILL_COUNT);
	filename_write_all(path, contents);

	/* ./project/src/project_main.c */
	basename = put_string(base, raw_name);
	strcpy(basename, "_main.c");
	build_contents(contents,
		       name_map,
		       MAIN_TEMPLATE,
		       MAIN_FILL_MAP,
		       MAIN_FILL_COUNT);
	filename_write_all(path, contents);

	/* ./project/src/project.h */
	strcpy(basename, ".h");
	build_contents(contents,
		       name_map,
		       HEADER_TEMPLATE,
		       HEADER_FILL_MAP,
		       HEADER_FILL_COUNT);
	filename_write_all(path, contents);

	/* ./project/src/Makefile */
	strcpy(base, "Makefile");
	build_contents(contents,
		       name_map,
		       INNER_MAKE_TEMPLATE,
		       INNER_MAKE_FILL_MAP,
		       INNER_MAKE_FILL_COUNT);
	filename_write_all(path, contents);

	/* ./project/test */
	base = stpcpy(root, "test");
	HANDLE_MKDIR_DEFAULT(path);
	PUT_FILE_DELIM(base);

	/* ./project/test/project_test.c */
	basename = put_string(base, raw_name);
	strcpy(basename, "_test.c");
	build_contents(contents,
		       name_map,
		       TEST_TEMPLATE,
		       TEST_FILL_MAP,
		       TEST_FILL_COUNT);
	filename_write_all(path, contents);


	/* ./project/test/test_runners */
	strcpy(base, "test_runners");
	HANDLE_MKDIR_DEFAULT(path);

	return 0;
}
