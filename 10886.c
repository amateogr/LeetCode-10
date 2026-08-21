#include <stdlib.h>
#include <string.h>

typedef struct {
    char word[201];
    int c1;
    int c2;
} Entry;

char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    Entry entries[200];
    int size = 0;

    char* token = strtok(s1, " ");
    while (token) {
        int found = 0;
        for (int i = 0; i < size; i++) {
            if (!strcmp(entries[i].word, token)) {
                entries[i].c1++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(entries[size].word, token);
            entries[size].c1 = 1;
            entries[size].c2 = 0;
            size++;
        }
        token = strtok(NULL, " ");
    }

    token = strtok(s2, " ");
    while (token) {
        int found = 0;
        for (int i = 0; i < size; i++) {
            if (!strcmp(entries[i].word, token)) {
                entries[i].c2++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(entries[size].word, token);
            entries[size].c1 = 0;
            entries[size].c2 = 1;
            size++;
        }
        token = strtok(NULL, " ");
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        if ((entries[i].c1 == 1 && entries[i].c2 == 0) || (entries[i].c1 == 0 && entries[i].c2 == 1)) {
            count++;
        }
    }

    char** result = malloc(count * sizeof(char*));
    int idx = 0;
    for (int i = 0; i < size; i++) {
        if ((entries[i].c1 == 1 && entries[i].c2 == 0) || (entries[i].c1 == 0 && entries[i].c2 == 1)) {
            result[idx++] = strdup(entries[i].word);
        }
    }

    *returnSize = count;
    return result;
}