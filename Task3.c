#include "C:\projectC\string\string_.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;


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

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace  (beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartTransform(char *s) {
    char *beginSearch = s;

    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }

}

void test_1() {
    char s[] = "A32BC1";
    digitToStartTransform(s);

    ASSERT_STRING("123ABC",s);
}

void test_2() { //54345XD
    char s[] = "AB345XD";
    digitToStartTransform(s);

    ASSERT_STRING("543ABXD",s);
}

void test_3() {
    char s[] = "a";
    digitToStartTransform(s);

    ASSERT_STRING("a",s);
}

void test_4() {
    char s[] = " AB345XD ";
    digitToStartTransform(s);

    ASSERT_STRING(" 543ABXD ",s);
}

void test_5() {
    char s[] = "AB345XD A32BC1";
    digitToStartTransform(s);

    ASSERT_STRING("543ABXD 123ABC",s);
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