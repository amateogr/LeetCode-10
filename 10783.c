#include <limits.h>

void inorder(struct TreeNode* node, struct TreeNode** prev, int* min_val) {
    if (!node) return;
    inorder(node->left, prev, min_val);
    if (*prev) {
        int diff = node->val - (*prev)->val;
        if (diff < *min_val) *min_val = diff;
    }
    *prev = node;
    inorder(node->right, prev, min_val);
}

int minDiffInBST(struct TreeNode* root) {
    int min_val = INT_MAX;
    struct TreeNode* prev = NULL;
    inorder(root, &prev, &min_val);
    return min_val;
}