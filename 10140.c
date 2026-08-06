#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct TrieNode {
    struct TrieNode* c[26];
    bool end;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->end = false;
    for (int i = 0; i < 26; i++) node->c[i] = NULL;
    return node;
}

void insert(TrieNode* root, char* word) {
    TrieNode* curr = root;
    while (*word) {
        int idx = *word - 'a';
        if (!curr->c[idx]) curr->c[idx] = createNode();
        curr = curr->c[idx];
        word++;
    }
    curr->end = true;
}

void dfs(char* s, int idx, TrieNode* root, char* path, int pathLen, char*** res, int* resSize, int* resCapacity) {
    if (s[idx] == '\0') {
        path[pathLen - 1] = '\0';
        if (*resSize >= *resCapacity) {
            *resCapacity *= 2;
            *res = (char**)realloc(*res, *resCapacity * sizeof(char*));
        }
        (*res)[(*resSize)++] = strdup(path);
        return;
    }
    TrieNode* curr = root;
    for (int i = idx; s[i] != '\0'; i++) {
        int ch = s[i] - 'a';
        if (!curr->c[ch]) break;
        curr = curr->c[ch];
        if (curr->end) {
            int len = i - idx + 1;
            int oldPathLen = pathLen;
            memcpy(path + pathLen, s + idx, len);
            pathLen += len;
            path[pathLen++] = ' ';
            path[pathLen] = '\0';
            dfs(s, i + 1, root, path, pathLen, res, resSize, resCapacity);
            pathLen = oldPathLen;
            path[pathLen] = '\0';
        }
    }
}

char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
    TrieNode* root = createNode();
    for (int i = 0; i < wordDictSize; i++) {
        insert(root, wordDict[i]);
    }
    int n = strlen(s);
    int resCapacity = 100;
    int resSize = 0;
    char** res = (char**)malloc(resCapacity * sizeof(char*));
    char* path = (char*)malloc(2 * n + 2);
    dfs(s, 0, root, path, 0, &res, &resSize, &resCapacity);
    free(path);
    *returnSize = resSize;
    return res;
}