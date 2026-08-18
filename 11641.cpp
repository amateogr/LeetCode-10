class Solution {
public:
    int countVowelStrings(int n) {
        return static_cast<int>(1LL * (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24);
    }
};