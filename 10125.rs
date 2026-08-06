impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let iter = s.bytes()
            .filter(|b| b.is_ascii_alphanumeric())
            .map(|b| b.to_ascii_lowercase());
        
        let rev_iter = s.bytes()
            .filter(|b| b.is_ascii_alphanumeric())
            .map(|b| b.to_ascii_lowercase())
            .rev();

        iter.eq(rev_iter)
    }
}