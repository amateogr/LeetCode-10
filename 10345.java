class Solution {
    private static final boolean[] VOWELS = new boolean[128];

    static {
        char[] v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (char c : v) {
            VOWELS[c] = true;
        }
    }

    public String reverseVowels(String s) {
        char[] chars = s.toCharArray();
        int left = 0;
        int right = chars.length - 1;

        while (left < right) {
            while (left < right && !VOWELS[chars[left]]) {
                left++;
            }
            while (left < right && !VOWELS[chars[right]]) {
                right--;
            }
            if (left < right) {
                char temp = chars[left];
                chars[left++] = chars[right];
                chars[right--] = temp;
            }
        }

        return new String(chars);
    }
}