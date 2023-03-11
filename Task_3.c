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

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend);
    if (word->end == NULL)
        return 0;
    word->begin = findSpaceReverse(word->end,rend);

    word->begin++;
    word->end++;

    return 1;
}

void swap (char *a, char *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int strlenWord(char *begin, char *end) {
    int len = 0;

    while (begin++ != end)
        len++;
    return len;
}

void reverse(char *begin, char* end) {
    int len = strlenWord(begin, end) / 2;
    for (int i = 0; i < len; i++) {
        swap(begin++, --end);
    }
}


void reverseWord(char *s) {
    char *beginSearch = s;

    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        char *oldEnd = word.end;
        char *oldBegin = word.begin;

        reverse(oldBegin, oldEnd);
        beginSearch = word.end;
    }

}
void test_1() {
    char s[] = "A32BC1";
    reverseWord(s);

    ASSERT_STRING("1CB23A",s);
}

void test_2() { //54345XD
    char s[] = "AB345XD";
    reverseWord(s);

    ASSERT_STRING("DX543BA",s);
}

void test_3() {
    char s[] = "a";

    reverseWord(s);
    ASSERT_STRING("a",s);
}

void test_4() {
    char s[] = "AB345XD A32BC1";
    reverseWord(s);

    ASSERT_STRING("DX543BA 1CB23A",s);
}

void test_5() {
    char s[] = "";

    reverseWord(s);
    ASSERT_STRING("",s);
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
