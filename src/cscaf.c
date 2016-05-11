#include <ctype.h>	/* toupper */
#include "cscaf.h"

#define HEADER_SEG_COUNT 4ul
static const char *HEADER_SEGS[HEADER_SEG_COUNT] = {
	  "#ifndef ",
	"_H_\n#define ",
	"_H_\n"
	"\n#ifdef __cplusplus /* ensure C linkage */"
	"\nextern \"C\" {"
	"\n#ifndef restrict /* replace 'restrict' with c++ compatible '__restrict__' */"
	"\n#define restrict __restrict__"
	"\n#endif"
	"\n#endif"
	"\n"
	"\n/* EXTERNAL DEPENDENCIES"
	"\n * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */"
	"\n/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲"
	"\n * EXTERNAL DEPENDENCIES"
	"\n *"
	"\n *"
	"\n * TYPEDEFS, ENUM AND STRUCT DEFINITIONS"
	"\n * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */"
	"\n/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲"
	"\n * TYPEDEFS, ENUM AND STRUCT DEFINITIONS"
	"\n *"
	"\n *"
	"\n * CONSTANTS"
	"\n * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */"
	"\n/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲"
	"\n * CONSTANTS"
	"\n *"
	"\n *"
	"\n * FUNCTION-LIKE MACROS"
	"\n * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */"
	"\n/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲"
	"\n * FUNCTION-LIKE MACROS"
	"\n *"
	"\n *"
	"\n * TOP-LEVEL FUNCTIONS"
	"\n * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */"
	"\n/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲"
	"\n * TOP-LEVEL FUNCTIONS"
	"\n *"
	"\n *"
	"\n * HELPER FUNCTIONS"
	"\n * ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ */"
	"\n/* ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲"
	"\n * HELPER FUNCTIONS */"
	"\n"
	"\n#ifdef __cplusplus /* close 'extern \"C\" {' */"
	"\n}"
	"\n#endif /* ifndef ",
	"_H_ */"
};

#define MAKE_SEG_COUNT 2ul
static const char *MAKE_SEGS[MAKE_SEG_COUNT] = {
	"\nCC     = gcc"
	"\nCFLAGS = -g -I. -std=c99 -Wall -D__USE_FIXED_PROTOTYPES__"
	"\nPROG   = ",
	"\n"
	"\n$(PROG): %.o"
	"\n\t$(CC) $(CFLAGS) -o $@ $^"
	"\n"
	"\n%.o: %.c %.h"
	"\n\t$(CC) $(CFLAGS) -c -o $@ $<"
	"\n"
	"\nclean:"
	"\n\t$(RM) $(PROG) *.o"
};

#define SOURCE_SEG_COUNT 2ul
static const char *SOURCE_SEGS[SOURCE_SEG_COUNT] = {
"#include \"",
".h\""
"\n"
"\nint main(int argc, char *argv[])"
"\n{"
"\n\treturn 0;"
"\n}"
};

int main(int argc, char *argv[])
{
	char *cwd;
	char *cap_name;

	if (argc < 2)
		EXIT_ON_FAILURE("missing project name");


	const char *const raw_name = argv[1];
	const char *const cap_name = capitalize_string(raw_name);

	HANDLE_GETCWD(cwd);

	printf("%s\n", cwd);

	return 0;
}


inline char *capitalize_string(char *restrict string)
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
