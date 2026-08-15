#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    int score;
    int index;
} Athlete;

int compare(const void* a, const void* b) {
    return ((Athlete*)b)->score - ((Athlete*)a)->score;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    *returnSize = scoreSize;
    char** answer = malloc(scoreSize * sizeof(char*));
    Athlete* athletes = malloc(scoreSize * sizeof(Athlete));
    
    for (int i = 0; i < scoreSize; ++i) {
        athletes[i].score = score[i];
        athletes[i].index = i;
    }
    
    qsort(athletes, scoreSize, sizeof(Athlete), compare);
    
    for (int i = 0; i < scoreSize; ++i) {
        int idx = athletes[i].index;
        if (i == 0) {
            answer[idx] = strdup("Gold Medal");
        } else if (i == 1) {
            answer[idx] = strdup("Silver Medal");
        } else if (i == 2) {
            answer[idx] = strdup("Bronze Medal");
        } else {
            answer[idx] = malloc(16);
            sprintf(answer[idx], "%d", i + 1);
        }
    }
    
    free(athletes);
    return answer;
}