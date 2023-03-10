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

char* getEndOfString(char *s) {
    return strlen_(s) + s;
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);

    *destination = '\0';
}

void test_1() {
    char s[] = "g   a";
    removeNonLetters(s);

    ASSERT_STRING("ga",s);
}

void test_2() {
    char s[] = "   ";
    removeNonLetters(s);

    ASSERT_STRING("",s);
}

void test_3() {
    char s[] = "ga";
    removeNonLetters(s);

    ASSERT_STRING("ga",s);
}

void test_4() {
    char s[] = "g a b f           a";
    removeNonLetters(s);

    ASSERT_STRING("gabfa",s);
}

void test_5() {
    char s[] = "  g   a  ";
    removeNonLetters(s);

    ASSERT_STRING("ga",s);
}

void testcases() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
}

int main() {
    testcases();

    return 0;
}