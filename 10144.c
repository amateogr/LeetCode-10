int count(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + count(root->left) + count(root->right);
}

void fill(struct TreeNode* root, int* arr, int* i) {
    if (!root) return;
    arr[(*i)++] = root->val;
    fill(root->left, arr, i);
    fill(root->right, arr, i);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = count(root);
    int* arr = malloc(sizeof(int) * (*returnSize));
    int i = 0;
    fill(root, arr, &i);
    return arr;
}