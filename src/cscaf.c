#include <ctype.h>	/* toupper */
#include "cscaf.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
		EXIT_ON_FAILURE("missing project name");


	const char *const raw_name = argv[1];
	const char *const cap_name = capitalize_string(raw_name);

	char dir[MAXPATHLEN];

	char *const root = make_root_dir(&dir[0], raw_name);

	strcpy(root, "LICENSE");
	write_to_file(dir, LICENSE);

	strcpy(root, "Makefile");
	write_to_file(dir, OUTER_MAKE);

	return 0;
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

	HANDLE_MKDIR(dir, DEFAULT_PERMISSIONS);

	PUT_SLASH(base);

	return base;
}


inline void write_to_file(const char *restrict filename,
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
