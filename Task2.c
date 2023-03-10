#include "C:\projectC\string\string_.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void removeAdjacentEqualLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *beginSource = s;
    char *destination = s;

    while( beginSource != endSource) {
            memcpy(destination, beginSource, sizeof(char));
            destination++;

            int ch = *beginSource;
            beginSource++;

            while (*beginSource == ch)
                beginSource++;
        }

    *destination = '\0';
}

void test_1() {
    char s[] = "";
    removeAdjacentEqualLetters(s);

    ASSERT_STRING("",s);
}

void test_2() {
    char s[] = "a";
    removeAdjacentEqualLetters(s);

    ASSERT_STRING("a",s);
}

void test_3() {
    char s[] = "aa";
    removeAdjacentEqualLetters(s);

    ASSERT_STRING("a",s);
}

void test_4() {
    char s[] = "aa bbb c";
    removeAdjacentEqualLetters(s);

    ASSERT_STRING("a b c",s);
}

void test_5() {
    char s[] = "aa bb";
    removeAdjacentEqualLetters(s);

    ASSERT_STRING("a b",s);
}

void test_6() {
    char s[] = "aabcdqqqb hh h h h h h bbaaa";
    removeAdjacentEqualLetters(s);

    ASSERT_STRING("abcdqb h h h h h h ba",s);
}

void testcases() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
}

int main() {
    testcases();

    return 0;
}