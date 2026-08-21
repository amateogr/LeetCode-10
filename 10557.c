char* reverseWords(char* s) {
    char *ptr = s, *start = s;
    while (*ptr) {
        if (*ptr == ' ') {
            char *end = ptr - 1;
            while (start < end) {
                char tmp = *start;
                *start++ = *end;
                *end-- = tmp;
            }
            start = ptr + 1;
        }
        ptr++;
    }
    char *end = ptr - 1;
    while (start < end) {
        char tmp = *start;
        *start++ = *end;
        *end-- = tmp;
    }
    return s;
}