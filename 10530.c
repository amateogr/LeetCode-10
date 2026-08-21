int getMinimumDifference(struct TreeNode* root) {
    int min_diff = 1e9;
    int prev = -1;
    struct TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            if (prev != -1) {
                int diff = curr->val - prev;
                if (diff < min_diff) min_diff = diff;
            }
            prev = curr->val;
            curr = curr->right;
        } else {
            struct TreeNode* pre = curr->left;
            while (pre->right != NULL && pre->right != curr) {
                pre = pre->right;
            }
            if (pre->right == NULL) {
                pre->right = curr;
                curr = curr->left;
            } else {
                pre->right = NULL;
                if (prev != -1) {
                    int diff = curr->val - prev;
                    if (diff < min_diff) min_diff = diff;
                }
                prev = curr->val;
                curr = curr->right;
            }
        }
    }
    return min_diff;
}