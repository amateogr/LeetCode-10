use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn helper(node: &Option<Rc<RefCell<TreeNode>>>, current: i32) -> i32 {
            match node {
                Some(n) => {
                    let n = n.borrow();
                    let next = current * 10 + n.val;
                    if n.left.is_none() && n.right.is_none() {
                        next
                    } else {
                        helper(&n.left, next) + helper(&n.right, next)
                    }
                }
                None => 0,
            }
        }
        helper(&root, 0)
    }
}