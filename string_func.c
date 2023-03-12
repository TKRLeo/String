//
// Created by Лев on 09.03.2023.
//

#include <ctype.h>
#include "string_.h"
char _stringBuffer[MAX_STRING_SIZE + 1];

size_t strlen_(char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char* find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char* findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

char* findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;
    return begin;
}

char* findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs == *rhs && *lhs != '\0' && *rhs != '\0') {
        ++lhs; ++rhs;
    }

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination) {
    memcpy(beginDestination, beginSource, (endSource - beginSource) * sizeof(char));

    return beginDestination + (endSource - beginSource);
}

char* copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int)) {

    while (beginSource != endSource) {
        if (f(*beginSource)) {
            memcpy(beginDestination, beginSource, sizeof(char));
            beginSource++; beginDestination++;
        } else
            beginSource++;
    }

    return beginDestination;
}

char* copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int)) {
    if(rbeginSource == rendSource)
        return beginDestination;

    while (rbeginSource != rendSource) {
        if (f(*rbeginSource)) {
            memcpy(beginDestination, rbeginSource, sizeof(char));
            beginDestination++; rbeginSource--;
        }
        else
            rbeginSource--;
    }

    return beginDestination;
}

char* getEndOfString(char *s) {
    return strlen_(s) + s;
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);

    *destination = '\0';
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


int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace  (beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

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
