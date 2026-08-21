#include <stdbool.h>

bool isLongPressedName(char* name, char* typed) {
    int i = 0, j = 0;
    while (typed[j] != '\0') {
        if (name[i] != '\0' && name[i] == typed[j]) {
            i++;
            j++;
        } else if (j > 0 && typed[j] == typed[j - 1]) {
            j++;
        } else {
            return false;
        }
    }
    return name[i] == '\0';
}