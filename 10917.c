#include <string.h>

char* reverseOnlyLetters(char* s) {
    char *l = s, *r = s + strlen(s) - 1;
    while (l < r) {
        while (l < r && !((*l | 32) >= 'a' && (*l | 32) <= 'z')) l++;
        while (l < r && !((*r | 32) >= 'a' && (*r | 32) <= 'z')) r--;
        if (l < r) {
            char t = *l;
            *l++ = *r;
            *r-- = t;
        }
    }
    return s;
}