impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 || (x % 10 == 0 && x != 0) {
            return false;
        }
        
        let mut reverted_number = 0;
        let mut x = x;
        
        while x > reverted_number {
            reverted_number = reverted_number * 10 + x % 10;
            x /= 10;
        }
        
        x == reverted_number || x == reverted_number / 10
    }
}