class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        boolean[] exists = new boolean[1001];
        for (int num : nums1) {
            exists[num] = true;
        }
        
        boolean[] intersected = new boolean[1001];
        int count = 0;
        for (int num : nums2) {
            if (exists[num] && !intersected[num]) {
                intersected[num] = true;
                count++;
            }
        }
        
        int[] result = new int[count];
        int index = 0;
        for (int i = 0; i <= 1000; i++) {
            if (intersected[i]) {
                result[index++] = i;
            }
        }
        
        return result;
    }
}