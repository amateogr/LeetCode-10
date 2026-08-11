#include <string>
#include <algorithm>
#include <cctype>

class Solution {
public:
    int strongPasswordChecker(std::string password) {
        const int n = password.length();
        const int missing = getMissing(password);
        int replaces = 0;
        int oneSeq = 0;
        int twoSeq = 0;

        for (int i = 2; i < n;) {
            if (password[i] == password[i - 1] && password[i - 1] == password[i - 2]) {
                int length = 2;
                while (i < n && password[i] == password[i - 1]) {
                    ++length;
                    ++i;
                }
                replaces += length / 3;
                if (length % 3 == 0) ++oneSeq;
                if (length % 3 == 1) ++twoSeq;
            } else {
                ++i;
            }
        }

        if (n < 6) return std::max(6 - n, missing);
        if (n <= 20) return std::max(replaces, missing);

        const int deletes = n - 20;
        replaces -= std::min(oneSeq, deletes);
        replaces -= std::min(std::max(deletes - oneSeq, 0), twoSeq * 2) / 2;
        replaces -= std::max(deletes - oneSeq - twoSeq * 2, 0) / 3;

        return deletes + std::max(replaces, missing);
    }

private:
    int getMissing(const std::string& password) {
        return 3 - std::any_of(password.begin(), password.end(), [](unsigned char c) { return std::isupper(c); })
                 - std::any_of(password.begin(), password.end(), [](unsigned char c) { return std::islower(c); })
                 - std::any_of(password.begin(), password.end(), [](unsigned char c) { return std::isdigit(c); });
    }
};