public class Solution {
    public bool IsMatch(string s, string p) {
        int sLen = s.Length;
        int pLen = p.Length;
        int sIdx = 0;
        int pIdx = 0;
        int starIdx = -1;
        int matchIdx = 0;

        while (sIdx < sLen) {
            if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            } else if (pIdx < pLen && p[pIdx] == '*') {
                starIdx = pIdx;
                matchIdx = sIdx;
                pIdx++;
            } else if (starIdx != -1) {
                pIdx = starIdx + 1;
                matchIdx++;
                sIdx = matchIdx;
            } else {
                return false;
            }
        }

        while (pIdx < pLen && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == pLen;
    }
}