use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn min_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match root {
            None => 0,
            Some(node) => {
                let borrowed = node.borrow();
                match (&borrowed.left, &borrowed.right) {
                    (None, None) => 1,
                    (Some(l), None) => Self::min_depth(Some(Rc::clone(l))) + 1,
                    (None, Some(r)) => Self::min_depth(Some(Rc::clone(r))) + 1,
                    (Some(l), Some(r)) => 1 + std::cmp::min(
                        Self::min_depth(Some(Rc::clone(l))),
                        Self::min_depth(Some(Rc::clone(r)))
                    ),
                }
            }
        }
    }
}