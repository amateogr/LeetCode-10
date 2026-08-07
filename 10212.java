import java.util.ArrayList;
import java.util.List;

class Solution {
    private static class TrieNode {
        TrieNode[] children = new TrieNode[26];
        String word;
    }

    public List<String> findWords(char[][] board, String[] words) {
        TrieNode root = new TrieNode();
        for (String w : words) {
            TrieNode curr = root;
            for (char c : w.toCharArray()) {
                int i = c - 'a';
                if (curr.children[i] == null) {
                    curr.children[i] = new TrieNode();
                }
                curr = curr.children[i];
            }
            curr.word = w;
        }

        List<String> res = new ArrayList<>();
        int rows = board.length;
        int cols = board[0].length;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root, res);
            }
        }
        return res;
    }

    private void dfs(char[][] board, int r, int c, TrieNode parent, List<String> res) {
        char ch = board[r][c];
        int idx = ch - 'a';
        if (ch == '#' || parent.children[idx] == null) return;
        TrieNode curr = parent.children[idx];
        if (curr.word != null) {
            res.add(curr.word);
            curr.word = null;
        }

        board[r][c] = '#';
        int[] dr = {-1, 0, 1, 0};
        int[] dc = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < board.length && nc >= 0 && nc < board[0].length && board[nr][nc] != '#') {
                dfs(board, nr, nc, curr, res);
            }
        }
        board[r][c] = ch;

        boolean hasChildren = false;
        for (int i = 0; i < 26; i++) {
            if (curr.children[i] != null) {
                hasChildren = true;
                break;
            }
        }
        if (!hasChildren) {
            parent.children[idx] = null;
        }
    }
}