class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int storeIndex = 0;
        int i = 0;
        while (i < n) {
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;
            if (storeIndex != 0) s[storeIndex++] = ' ';
            int j = i;
            while (j < n && s[j] != ' ') j++;
            while (i < j) s[storeIndex++] = s[i++];
        }
        s.resize(storeIndex);
        reverse(s.begin(), s.end());
        i = 0;
        while (i < storeIndex) {
            int j = i;
            while (j < storeIndex && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        return s;
    }
};