class Solution {
    public int oddCells(int m, int n, int[][] indices) {
        int[] rows = new int[m];
        int[] cols = new int[n];
        
        for (int[] index : indices) {
            rows[index[0]]++;
            cols[index[1]]++;
        }
        
        int oddRows = 0;
        for (int r : rows) {
            if ((r & 1) != 0) {
                oddRows++;
            }
        }
        
        int oddCols = 0;
        for (int c : cols) {
            if ((c & 1) != 0) {
                oddCols++;
            }
        }
        
        return oddRows * (n - oddCols) + oddCols * (m - oddRows);
    }
}