public class Solution {
    public int LengthOfLongestSubstring(string s) {
        int n = s.Length;
        int maxLength = 0;
        HashSet<char> set = new HashSet<char>();
        int left = 0;
        for (int right = 0; right < n; right++) {
            while (set.Contains(s[right])) {
                set.Remove(s[left]);
                left++;
            }
            set.Add(s[right]);
            maxLength = Math.Max(maxLength, right - left + 1);
        }
        return maxLength;
    }
}