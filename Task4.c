#include "string\string_.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

#define SPACE ' '

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


char* addSpaces(char *ptr, char *s,char *ptrRead) {
    char buff[MAX_STRING_SIZE + 1];
    memcpy(buff, ptrRead, sizeof(char));
    int value = atoi(buff);

    while (value--) {
        *ptr++ = SPACE;
    }

    return ptr;
}

void replaceDigitToSpaces(char *s) {
    int len_s = strlen_(s);
    char* endSource = s + len_s;

    char *buff = copy(s, endSource, _stringBuffer);

    char *recPtr = s;
    char *readPtr = buff - len_s;

    while (readPtr != buff) {
        if (isdigit(*readPtr)) {
            recPtr = addSpaces(recPtr,s,readPtr);
            readPtr++;
        } else {
            memcpy(recPtr, readPtr, sizeof(char));
            readPtr++; recPtr++;
        }
    }
    *recPtr = '\0';

}
void test_1() {
    char s[MAX_STRING_SIZE] = "a3b";
    replaceDigitToSpaces(s);
    ASSERT_STRING("a   b",s);
}

void test_2() { //54345XD
    char s[MAX_STRING_SIZE] = "a3b3c";

    replaceDigitToSpaces(s);

    ASSERT_STRING("a   b   c",s);
}

void test_3() {
    char s[MAX_STRING_SIZE] = "3";

    replaceDigitToSpaces(s);

    ASSERT_STRING("   ",s);
}

void test_4() {
    char s[MAX_STRING_SIZE] = "AB345XD A32BC1";
    replaceDigitToSpaces(s);

    ASSERT_STRING("AB            XD A     BC ",s);
}

void test_5() {
    char s[MAX_STRING_SIZE] = "";
    replaceDigitToSpaces(s);

    ASSERT_STRING("",s);
}


void testcases() {
    test_4();
    test_1();
    test_2();
    test_3();
    test_5() ;

}
int main() {
   testcases();

    return 0;
}
