import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    class TrieNode {
        int index = -1;
        int[] list = new int[2];
        int size = 0;
        TrieNode[] children = new TrieNode[26];

        void addToList(int val) {
            if (size == list.length) {
                int[] newList = new int[list.length * 2];
                System.arraycopy(list, 0, newList, 0, list.length);
                list = newList;
            }
            list[size++] = val;
        }
    }

    TrieNode root = new TrieNode();

    public List<List<Integer>> palindromePairs(String[] words) {
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            add(words[i], i);
        }
        for (int i = 0; i < words.length; i++) {
            search(words[i], i, res);
        }
        return res;
    }

    private void add(String word, int index) {
        TrieNode curr = root;
        for (int i = word.length() - 1; i >= 0; i--) {
            if (isPalindrome(word, 0, i)) {
                curr.addToList(index);
            }
            int c = word.charAt(i) - 'a';
            if (curr.children[c] == null) {
                curr.children[c] = new TrieNode();
            }
            curr = curr.children[c];
        }
        curr.addToList(index);
        curr.index = index;
    }

    private void search(String word, int index, List<List<Integer>> res) {
        TrieNode curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr.index >= 0 && curr.index != index && isPalindrome(word, i, word.length() - 1)) {
                res.add(Arrays.asList(index, curr.index));
            }
            curr = curr.children[word.charAt(i) - 'a'];
            if (curr == null) return;
        }
        for (int i = 0; i < curr.size; i++) {
            if (curr.list[i] == index) continue;
            res.add(Arrays.asList(index, curr.list[i]));
        }
    }

    private boolean isPalindrome(String word, int i, int j) {
        while (i < j) {
            if (word.charAt(i++) != word.charAt(j--)) return false;
        }
        return true;
    }
}