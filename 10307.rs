struct NumArray {
    tree: Vec<i32>,
    nums: Vec<i32>,
}

impl NumArray {
    fn new(nums: Vec<i32>) -> Self {
        let n = nums.len();
        let mut res = Self {
            tree: vec![0; n + 1],
            nums: vec![0; n],
        };
        for i in 0..n {
            res.update(i as i32, nums[i]);
        }
        res
    }
    
    fn update(&mut self, index: i32, val: i32) {
        let idx = index as usize;
        let diff = val - self.nums[idx];
        self.nums[idx] = val;
        let mut i = idx + 1;
        while i < self.tree.len() {
            self.tree[i] += diff;
            i += i & (!i + 1);
        }
    }
    
    fn sum_range(&self, left: i32, right: i32) -> i32 {
        self.prefix_sum(right + 1) - self.prefix_sum(left)
    }
    
    fn prefix_sum(&self, mut i: i32) -> i32 {
        let mut sum = 0;
        while i > 0 {
            sum += self.tree[i as usize];
            i -= i & -i;
        }
        sum
    }
}