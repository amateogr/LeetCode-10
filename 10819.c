#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_SIZE 1024

typedef struct Node {
    char *word;
    int count;
    struct Node *next;
} Node;

static inline unsigned int hash(const char *str) {
    unsigned int h = 5381;
    int c;
    while ((c = *str++))
        h = ((h << 5) + h) + c;
    return h & (HASH_SIZE - 1);
}

char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {
    Node *table[HASH_SIZE] = {0};
    
    for (int i = 0; i < bannedSize; i++) {
        unsigned int h = hash(banned[i]);
        Node *curr = table[h];
        int found = 0;
        while (curr) {
            if (strcmp(curr->word, banned[i]) == 0) {
                curr->count = -1;
                found = 1;
                break;
            }
            curr = curr->next;
        }
        if (!found) {
            Node *node = (Node*)malloc(sizeof(Node));
            node->word = strdup(banned[i]);
            node->count = -1;
            node->next = table[h];
            table[h] = node;
        }
    }

    char word[1024];
    int w_idx = 0;
    char *p = paragraph;

    while (1) {
        if (*p && isalpha((unsigned char)*p)) {
            word[w_idx++] = tolower((unsigned char)*p);
        } else {
            if (w_idx > 0) {
                word[w_idx] = '\0';
                unsigned int h = hash(word);
                Node *curr = table[h];
                int found = 0;
                while (curr) {
                    if (strcmp(curr->word, word) == 0) {
                        if (curr->count != -1) {
                            curr->count++;
                        }
                        found = 1;
                        break;
                    }
                    curr = curr->next;
                }
                if (!found) {
                    Node *node = (Node*)malloc(sizeof(Node));
                    node->word = strdup(word);
                    node->count = 1;
                    node->next = table[h];
                    table[h] = node;
                }
                w_idx = 0;
            }
            if (!*p) break;
        }
        p++;
    }

    char *max_word = NULL;
    int max_count = -1;

    for (int i = 0; i < HASH_SIZE; i++) {
        Node *curr = table[i];
        while (curr) {
            if (curr->count > max_count) {
                max_count = curr->count;
                max_word = curr->word;
            }
            curr = curr->next;
        }
    }

    char *result = strdup(max_word);

    for (int i = 0; i < HASH_SIZE; i++) {
        Node *curr = table[i];
        while (curr) {
            Node *temp = curr;
            curr = curr->next;
            free(temp->word);
            free(temp);
        }
    }

    return result;
}