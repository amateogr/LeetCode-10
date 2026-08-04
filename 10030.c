#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 10007

typedef struct HashNode {
    char* str;
    int id;
    struct HashNode* next;
} HashNode;

unsigned int hash(const char* str, int len) {
    unsigned int h = 5381;
    for (int i = 0; i < len; i++) {
        h = ((h << 5) + h) + str[i];
    }
    return h % HASH_SIZE;
}

int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize) {
    int s_len = strlen(s);
    int word_len = strlen(words[0]);
    int total_len = wordsSize * word_len;
    *returnSize = 0;
    
    if (s_len < total_len) return NULL;
    
    int* result = (int*)malloc(s_len * sizeof(int));
    HashNode** table = (HashNode**)calloc(HASH_SIZE, sizeof(HashNode*));
    int word_counts[5000] = {0};
    int unique_count = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        unsigned int h = hash(words[i], word_len);
        HashNode* node = table[h];
        int found_id = -1;
        while (node != NULL) {
            if (strncmp(node->str, words[i], word_len) == 0) {
                found_id = node->id;
                break;
            }
            node = node->next;
        }
        if (found_id == -1) {
            HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
            new_node->str = words[i];
            new_node->id = unique_count;
            new_node->next = table[h];
            table[h] = new_node;
            word_counts[unique_count] = 1;
            unique_count++;
        } else {
            word_counts[found_id]++;
        }
    }
    
    int* s_word_ids = (int*)malloc(s_len * sizeof(int));
    for (int i = 0; i <= s_len - word_len; i++) {
        s_word_ids[i] = -1;
        unsigned int h = hash(s + i, word_len);
        HashNode* node = table[h];
        while (node != NULL) {
            if (strncmp(node->str, s + i, word_len) == 0) {
                s_word_ids[i] = node->id;
                break;
            }
            node = node->next;
        }
    }
    
    int window_counts[5000];
    for (int i = 0; i < word_len; i++) {
        int left = i;
        int right = i;
        int formed = 0;
        memset(window_counts, 0, sizeof(int) * unique_count);
        
        while (right <= s_len - word_len) {
            int id = s_word_ids[right];
            if (id != -1) {
                window_counts[id]++;
                if (window_counts[id] <= word_counts[id]) {
                    formed++;
                }
                while (window_counts[id] > word_counts[id]) {
                    int left_id = s_word_ids[left];
                    window_counts[left_id]--;
                    if (window_counts[left_id] < word_counts[left_id]) {
                        formed--;
                    }
                    left += word_len;
                }
                if (formed == wordsSize) {
                    result[(*returnSize)++] = left;
                }
                right += word_len;
            } else {
                memset(window_counts, 0, sizeof(int) * unique_count);
                formed = 0;
                right += word_len;
                left = right;
            }
        }
    }
    
    free(s_word_ids);
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* node = table[i];
        while (node != NULL) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(table);
    
    return result;
}