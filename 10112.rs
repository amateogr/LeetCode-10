use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> bool {
        let node = match root {
            Some(n) => n,
            None => return false,
        };
        let n = node.borrow();
        let sum = target_sum - n.val;
        if n.left.is_none() && n.right.is_none() {
            sum == 0
        } else {
            Self::has_path_sum(n.left.clone(), sum) || Self::has_path_sum(n.right.clone(), sum)
        }
    }
}