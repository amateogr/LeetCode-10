int balancedStringSplit(char * s) {
    int ans = 0, bal = 0;
    while (*s) {
        bal += (*s++ == 'L') ? 1 : -1;
        ans += (bal == 0);
    }
    return ans;
}