#include <stdbool.h>

int distinctIntegers(int n) {
    bool board[101] = {false};
    board[n] = true;
    bool updated = true;

    while (updated) {
        updated = false;
        for (int x = 1; x <= n; x++) {
            if (!board[x]) continue;
            for (int i = 1; i <= n; i++) {
                if (x % i == 1 && !board[i]) {
                    board[i] = true;
                    updated = true;
                }
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (board[i]) count++;
    }
    return count;
}