class Solution {
    public int minCostToMoveChips(int[] position) {
        int odd = 0;
        for (int p : position) {
            odd += p & 1;
        }
        return Math.min(odd, position.length - odd);
    }
}