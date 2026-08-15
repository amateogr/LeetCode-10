class Solution {
    public String tictactoe(int[][] moves) {
        int[] rows = new int[3];
        int[] cols = new int[3];
        int diag = 0;
        int antiDiag = 0;
        for (int i = 0; i < moves.length; i++) {
            int r = moves[i][0];
            int c = moves[i][1];
            int p = (i % 2 == 0) ? 1 : -1;
            rows[r] += p;
            cols[c] += p;
            if (r == c) diag += p;
            if (r + c == 2) antiDiag += p;
            if (Math.abs(rows[r]) == 3 || Math.abs(cols[c]) == 3 || Math.abs(diag) == 3 || Math.abs(antiDiag) == 3) {
                return p == 1 ? "A" : "B";
            }
        }
        return moves.length == 9 ? "Draw" : "Pending";
    }
}