#include <stdio.h>
#include <stdlib.h>

int minMaxDifference(int num) {
    char s[12], t[12];
    int len = sprintf(s, "%d", num);
    for (int i = 0; i < len; i++) t[i] = s[i];
    t[len] = '\0';

    char target_min = s[0];
    for (int i = 0; i < len; i++) {
        if (s[i] == target_min) s[i] = '0';
    }
    int mi = atoi(s);

    char target_max = 0;
    for (int i = 0; i < len; i++) {
        if (t[i] != '9') {
            target_max = t[i];
            break;
        }
    }

    if (target_max) {
        for (int i = 0; i < len; i++) {
            if (t[i] == target_max) t[i] = '9';
        }
    }
    int mx = atoi(t);

    return mx - mi;
}