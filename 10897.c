struct TreeNode* helper(struct TreeNode* root, struct TreeNode* prev) {
    if (!root) return prev;
    prev = helper(root->right, prev);
    root->right = prev;
    struct TreeNode* left = root->left;
    root->left = NULL;
    return helper(left, root);
}

struct TreeNode* increasingBST(struct TreeNode* root) {
    return helper(root, NULL);
}