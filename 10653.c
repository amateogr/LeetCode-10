#include <stdbool.h>

typedef struct {
    struct TreeNode* data[10000];
    int top;
} BSTStack;

static inline void push_left(BSTStack* s, struct TreeNode* node) {
    while (node) {
        s->data[++(s->top)] = node;
        node = node->left;
    }
}

static inline void push_right(BSTStack* s, struct TreeNode* node) {
    while (node) {
        s->data[++(s->top)] = node;
        node = node->right;
    }
}

bool findTarget(struct TreeNode* root, int k) {
    if (!root) return false;

    BSTStack left_stack;
    left_stack.top = -1;
    BSTStack right_stack;
    right_stack.top = -1;

    push_left(&left_stack, root);
    push_right(&right_stack, root);

    while (left_stack.top >= 0 && right_stack.top >= 0) {
        struct TreeNode* l_node = left_stack.data[left_stack.top];
        struct TreeNode* r_node = right_stack.data[right_stack.top];

        if (l_node == r_node) break;

        int sum = l_node->val + r_node->val;
        if (sum == k) return true;

        if (sum < k) {
            left_stack.top--;
            push_left(&left_stack, l_node->right);
        } else {
            right_stack.top--;
            push_right(&right_stack, r_node->left);
        }
    }

    return false;
}