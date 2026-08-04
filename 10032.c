int longestValidParentheses(char* s) {
    int max_len = 0;
    int n = 0;
    while (s[n] != '\0') n++;
    int* st = (int*)malloc((n + 1) * sizeof(int));
    int top = -1;
    st[++top] = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st[++top] = i;
        } else {
            top--;
            if (top == -1) {
                st[++top] = i;
            } else {
                int len = i - st[top];
                if (len > max_len) max_len = len;
            }
        }
    }
    free(st);
    return max_len;
}