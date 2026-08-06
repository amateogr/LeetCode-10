use std::rc::Rc;
use std::cell::RefCell;
use std::cmp::max;

impl Solution {
    pub fn max_path_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max_sum = i32::MIN;
        Self::dfs(&root, &mut max_sum);
        max_sum
    }

    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, max_sum: &mut i32) -> i32 {
        match node {
            Some(n) => {
                let borrow = n.borrow();
                let left = max(0, Self::dfs(&borrow.left, max_sum));
                let right = max(0, Self::dfs(&borrow.right, max_sum));
                *max_sum = max(*max_sum, borrow.val + left + right);
                borrow.val + max(left, right)
            }
            None => 0,
        }
    }
}