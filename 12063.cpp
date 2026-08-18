class Solution {
public:
    long long countVowels(string word) {
        long long total = 0;
        long long n = word.length();
        for (long long i = 0; i < n; ++i) {
            char c = word[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                total += (i + 1) * (n - i);
            }
        }
        return total;
    }
};