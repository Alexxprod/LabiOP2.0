#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <memory.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 100

char _stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
char *begin;
char *end;
} WordDescriptor;



char *getEndOfString(char *begin) {
    char *end = begin;
    while (*end != '\0') {
        end++;
    }

    return end;
}


char *findNonSpace(char *begin) {
    while (isspace(*begin))
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (!isspace(*begin) && *begin != '\0')
        begin++;

    return begin;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);

    return beginDestination + (endSource - beginSource);
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }

        beginSource++;
    }

    return beginDestination;
}

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }

        rbeginSource--;
    }

    return beginDestination;
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);

    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}


void *sortLetters(WordDescriptor *word) {

}

int char_cmp(const void *pa, const void *pb) {
    char a = *(char*)pa;
    char b = *(char*)pb;
    return a - b;
}


int main() {
    char s[100] = "A32Bx afas fdja ksdjds adlk lksadjh C1";


    puts(s);

    return 0;
}

