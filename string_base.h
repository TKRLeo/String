//
// Created by Лев on 09.03.2023.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STRING_SIZE 100

char* _stringBuffer[MAX_STRING_SIZE + 1];

size_t strlen_(const char *begin) {
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


#ifndef UNTITLED_STRING__H
#define UNTITLED_STRING__H

#endif //UNTITLED_STRING__H

