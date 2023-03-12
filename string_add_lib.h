#include <memory.h>
#define MAX_STRING_SIZE 100

extern char _stringBuffer[MAX_STRING_SIZE + 1];
typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

size_t strlen_(char *begin);
char* find(char *begin, char *end, int ch);
char* findNonSpace(char *begin);
char* findSpace(char *begin);
char* findNonSpaceReverse(char *rbegin, const char *rend);
char *findSpaceReverse(char *rbegin, const char *rend);
int strcmp_(const char *lhs, const char *rhs);
char *copy(const char *beginSource, const char *endSource,
           char *beginDestination);
char* copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));
char* copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));
char* getEndOfString(char *s);
void removeNonLetters(char *s);
void removeAdjacentEqualLetters(char *s);
int getWord(char *beginSearch, WordDescriptor *word) ;
void swap (char *a, char *b);
int strlenWord(char *begin, char *end);
void reverse(char *begin, char* end);
void reverseWord(char *s);

