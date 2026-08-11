import java.util.Arrays;

class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        int n = envelopes.length;
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = ((long) envelopes[i][0] << 32) | (Integer.MAX_VALUE - envelopes[i][1]);
        }
        Arrays.sort(arr);
        
        int[] dp = new int[n];
        int len = 0;
        for (int i = 0; i < n; i++) {
            int h = Integer.MAX_VALUE - (int) arr[i];
            int idx = Arrays.binarySearch(dp, 0, len, h);
            if (idx < 0) {
                idx = -idx - 1;
            }
            dp[idx] = h;
            if (idx == len) {
                len++;
            }
        }
        return len;
    }
}