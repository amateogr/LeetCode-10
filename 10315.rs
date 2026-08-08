impl Solution {
    pub fn count_smaller(nums: Vec<i32>) -> Vec<i32> {
        let offset = 10000;
        let size = 20002;
        let mut tree = vec![0; size + 1];
        let mut res = vec![0; nums.len()];

        for i in (0..nums.len()).rev() {
            let val = (nums[i] + offset) as usize;
            
            let mut idx = val;
            let mut sum = 0;
            while idx > 0 {
                sum += tree[idx];
                idx -= idx & idx.wrapping_neg();
            }
            res[i] = sum;

            let mut idx = val + 1;
            while idx <= size {
                tree[idx] += 1;
                idx += idx & idx.wrapping_neg();
            }
        }
        res
    }
}