import java.util.HashSet;

class Solution {
    public boolean containsDuplicate(int[] nums) {
        var seen = new HashSet<Integer>(nums.length);
        for (int num : nums) {
            if (!seen.add(num)) {
                return true;
            }
        }
        return false;
    }
}