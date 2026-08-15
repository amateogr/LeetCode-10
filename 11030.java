class Solution {
    public int[][] allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        int total = rows * cols;
        int[][] res = new int[total][2];
        boolean[][] visited = new boolean[rows][cols];
        int[] qR = new int[total];
        int[] qC = new int[total];
        int head = 0, tail = 0;

        qR[tail] = rCenter;
        qC[tail] = cCenter;
        tail++;
        visited[rCenter][cCenter] = true;

        int index = 0;
        while (head < tail) {
            int r = qR[head];
            int c = qC[head];
            head++;

            res[index][0] = r;
            res[index][1] = c;
            index++;

            if (r + 1 < rows && !visited[r + 1][c]) {
                visited[r + 1][c] = true;
                qR[tail] = r + 1;
                qC[tail] = c;
                tail++;
            }
            if (r - 1 >= 0 && !visited[r - 1][c]) {
                visited[r - 1][c] = true;
                qR[tail] = r - 1;
                qC[tail] = c;
                tail++;
            }
            if (c + 1 < cols && !visited[r][c + 1]) {
                visited[r][c + 1] = true;
                qR[tail] = r;
                qC[tail] = c + 1;
                tail++;
            }
            if (c - 1 >= 0 && !visited[r][c - 1]) {
                visited[r][c - 1] = true;
                qR[tail] = r;
                qC[tail] = c - 1;
                tail++;
            }
        }

        return res;
    }
}