import java.util.TreeSet;

class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int maxSum = Integer.MIN_VALUE;

        if (rows < cols) {
            for (int r1 = 0; r1 < rows; r1++) {
                int[] colSums = new int[cols];
                for (int r2 = r1; r2 < rows; r2++) {
                    for (int c = 0; c < cols; c++) {
                        colSums[c] += matrix[r2][c];
                    }
                    TreeSet<Integer> set = new TreeSet<>();
                    set.add(0);
                    int currentSum = 0;
                    for (int sum : colSums) {
                        currentSum += sum;
                        Integer target = set.ceiling(currentSum - k);
                        if (target != null) {
                            maxSum = Math.max(maxSum, currentSum - target);
                        }
                        set.add(currentSum);
                    }
                    if (maxSum == k) return k;
                }
            }
        } else {
            for (int c1 = 0; c1 < cols; c1++) {
                int[] rowSums = new int[rows];
                for (int c2 = c1; c2 < cols; c2++) {
                    for (int r = 0; r < rows; r++) {
                        rowSums[r] += matrix[r][c2];
                    }
                    TreeSet<Integer> set = new TreeSet<>();
                    set.add(0);
                    int currentSum = 0;
                    for (int sum : rowSums) {
                        currentSum += sum;
                        Integer target = set.ceiling(currentSum - k);
                        if (target != null) {
                            maxSum = Math.max(maxSum, currentSum - target);
                        }
                        set.add(currentSum);
                    }
                    if (maxSum == k) return k;
                }
            }
        }
        return maxSum;
    }
}