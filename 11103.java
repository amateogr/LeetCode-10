class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        int give = 1;
        int idx = 0;
        while (candies > 0) {
            int current = candies < give ? candies : give;
            ans[idx] += current;
            candies -= current;
            give++;
            idx++;
            if (idx == num_people) {
                idx = 0;
            }
        }
        return ans;
    }
}