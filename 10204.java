class Solution {
    public int countPrimes(int n) {
        if (n <= 2) return 0;
        boolean[] composite = new boolean[n];
        int count = 1;
        int limit = (int) Math.sqrt(n);
        for (int i = 3; i < n; i += 2) {
            if (!composite[i]) {
                count++;
                if (i <= limit) {
                    for (int j = i * i; j < n; j += 2 * i) {
                        composite[j] = true;
                    }
                }
            }
        }
        return count;
    }
}