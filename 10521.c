#include <string.h>

int findLUSlength(char* a, char* b) {
    if (strcmp(a, b) == 0) return -1;
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    return len_a > len_b ? (int)len_a : (int)len_b;
}