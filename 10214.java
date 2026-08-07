class Solution {
    public String shortestPalindrome(String s) {
        int n = s.length();
        if (n == 0) return "";
        String rev = new StringBuilder(s).reverse().toString();
        String t = s + "#" + rev;
        int[] p = new int[t.length()];
        for (int i = 1; i < t.length(); i++) {
            int j = p[i - 1];
            while (j > 0 && t.charAt(i) != t.charAt(j)) {
                j = p[j - 1];
            }
            if (t.charAt(i) == t.charAt(j)) {
                j++;
            }
            p[i] = j;
        }
        return rev.substring(0, n - p[t.length() - 1]) + s;
    }
}