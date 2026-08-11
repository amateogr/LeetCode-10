class Solution {
    public boolean isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = num / mid;
            int rem = num % mid;
            
            if (res == mid && rem == 0) {
                return true;
            }
            
            if (res < mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return false;
    }
}