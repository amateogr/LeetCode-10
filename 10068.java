import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> res = new ArrayList<>();
        int n = words.length, i = 0;
        while (i < n) {
            int j = i, len = words[i].length();
            while (j + 1 < n && len + 1 + words[j + 1].length() <= maxWidth) {
                len += 1 + words[j + 1].length();
                j++;
            }
            StringBuilder sb = new StringBuilder();
            int numOfWords = j - i + 1;
            if (j == n - 1 || numOfWords == 1) {
                for (int k = i; k <= j; k++) {
                    sb.append(words[k]);
                    if (k < j) sb.append(" ");
                }
                sb.append(" ".repeat(maxWidth - sb.length()));
            } else {
                int totalChars = 0;
                for (int k = i; k <= j; k++) totalChars += words[k].length();
                int totalSpaces = maxWidth - totalChars;
                int spacesBetweenWords = totalSpaces / (numOfWords - 1);
                int extraSpaces = totalSpaces % (numOfWords - 1);
                for (int k = i; k <= j; k++) {
                    sb.append(words[k]);
                    if (k < j) {
                        int spaces = spacesBetweenWords + (k - i < extraSpaces ? 1 : 0);
                        sb.append(" ".repeat(spaces));
                    }
                }
            }
            res.add(sb.toString());
            i = j + 1;
        }
        return res;
    }
}