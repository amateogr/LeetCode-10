class Solution {
    public int numRookCaptures(char[][] board) {
        int r = 0, c = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    r = i;
                    c = j;
                    i = 8;
                    break;
                }
            }
        }
        
        int count = 0;
        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int ni = r, nj = c;
            while (true) {
                ni += dr[i];
                nj += dc[i];
                if (ni < 0 || ni >= 8 || nj < 0 || nj >= 8) break;
                char cell = board[ni][nj];
                if (cell == 'p') {
                    count++;
                    break;
                }
                if (cell == 'B') {
                    break;
                }
            }
        }
        
        return count;
    }
}