#include <string.h>

int countCharacters(char** words, int wordsSize, char* chars) {
    int base[26] = {0};
    for (char* p = chars; *p; ++p) {
        base[*p - 'a']++;
    }

    int total = 0;
    for (int i = 0; i < wordsSize; ++i) {
        int counts[26];
        __builtin_memcpy(counts, base, sizeof(base));
        
        char* w = words[i];
        int len = 0;
        int valid = 1;

        while (*w) {
            int idx = *w++ - 'a';
            if (--counts[idx] < 0) {
                valid = 0;
                break;
            }
            len++;
        }

        if (valid) {
            total += len;
        }
    }
    return total;
}