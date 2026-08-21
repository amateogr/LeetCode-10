int removePalindromeSub(char* s) {
    if (!s || !*s) return 0;
    char *end = s;
    while (*end) end++;
    end--;
    for (char *start = s; start < end; start++, end--) {
        if (*start != *end) return 2;
    }
    return 1;
}