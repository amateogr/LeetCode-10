#include <string>

class Solution {
public:
    bool hasSameDigits(std::string s) {
        while (s.length() > 2) {
            for (size_t i = 0; i < s.length() - 1; ++i) {
                s[i] = '0' + (s[i] - '0' + s[i + 1] - '0') % 10;
            }
            s.pop_back();
        }
        return s[0] == s[1];
    }
};