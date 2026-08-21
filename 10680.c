#include <stdbool.h>

static inline bool is_palindrome(const char* l, const char* r) {
    while (l < r) {
        if (*l != *r) return false;
        l++;
        r--;
    }
    return true;
}

bool validPalindrome(char* s) {
    const char* l = s;
    const char* r = s;
    while (*r) r++;
    r--;

    while (l < r) {
        if (*l != *r) {
            return is_palindrome(l + 1, r) || is_palindrome(l, r - 1);
        }
        l++;
        r--;
    }
    return true;
}