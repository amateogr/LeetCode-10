use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::check(&root) != -1
    }

    fn check(node: &Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let n = match node {
            Some(n) => n.borrow(),
            None => return 0,
        };
        let left = Self::check(&n.left);
        if left == -1 { return -1; }
        let right = Self::check(&n.right);
        if right == -1 { return -1; }
        if (left - right).abs() > 1 { return -1; }
        1 + left.max(right)
    }
}