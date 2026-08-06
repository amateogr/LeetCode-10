public class Solution {
    public int TitleToNumber(string columnTitle) {
        int result = 0;
        foreach (char c in columnTitle) {
            result = result * 26 + (c - 64);
        }
        return result;
    }
}