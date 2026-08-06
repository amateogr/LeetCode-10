int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void fillPostorder(struct TreeNode* root, int* arr, int* index) {
    if (!root) return;
    fillPostorder(root->left, arr, index);
    fillPostorder(root->right, arr, index);
    arr[(*index)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNodes(root);
    int* res = malloc(sizeof(int) * *returnSize);
    if (!res) return NULL;
    int index = 0;
    fillPostorder(root, res, &index);
    return res;
}