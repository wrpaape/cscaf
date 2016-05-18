#include <unity/unity.h>
#include "cscaf.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_capitalize_string(void)
{
	char *const string = "booga";

	TEST_ASSERT_EQUAL_STRING("BOOGA", capitalize_string(string));
}
