#include <stdlib.h>

static void traverse(struct TreeNode* root, int* prev, int* count, int* max_count, int* mode_count, int* res, int pass) {
    if (!root) return;
    traverse(root->left, prev, count, max_count, mode_count, res, pass);
    
    if (*count > 0 && root->val == *prev) {
        (*count)++;
    } else {
        *prev = root->val;
        *count = 1;
    }
    
    if (pass == 1) {
        if (*count > *max_count) *max_count = *count;
    } else {
        if (*count == *max_count) res[(*mode_count)++] = root->val;
    }
    
    traverse(root->right, prev, count, max_count, mode_count, res, pass);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    int max_count = 0, count = 0, prev = 0, mode_count = 0;
    traverse(root, &prev, &count, &max_count, &mode_count, NULL, 1);
    
    int* res = (int*)malloc(10000 * sizeof(int));
    count = 0;
    mode_count = 0;
    traverse(root, &prev, &count, &max_count, &mode_count, res, 2);
    
    *returnSize = mode_count;
    return res;
}