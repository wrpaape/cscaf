#include <ctype.h>	/* toupper */
#include "cscaf.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
		EXIT_ON_FAILURE("missing project name");


	const char *const raw_name = argv[1];
	const char *const cap_name = capitalize_string(raw_name);

	char dir[MAXPATHLEN];

	char *cwd;
	char *base;

	HANDLE_GETCWD(cwd);

	base = extend_string(dir, cwd);

	PUT_SLASH(base);

	copy_string(base, raw_name);


	printf("raw_name: %s\n", raw_name);
	printf("cap_name: %s\n", cap_name);
	printf("dir: %s\n", dir);

	char *const proj_root = base;

	HANDLE_MKDIR(&dir[0], DEFAULT_PERMISSIONS);

	return 0;
}


inline void copy_string(char *restrict buffer,
			const char *restrict string)
{
	while (1) {
		*buffer = *string;
		if (*string == '\0')
			break;
		++buffer;
		++string;
	}
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
