use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn flatten(root: &mut Option<Rc<RefCell<TreeNode>>>) {
        let mut curr = root.clone();
        while let Some(node) = curr {
            if node.borrow().left.is_some() {
                let mut pre = node.borrow().left.as_ref().unwrap().clone();
                while pre.borrow().right.is_some() {
                    let next = pre.borrow().right.as_ref().unwrap().clone();
                    pre = next;
                }
                let right = node.borrow_mut().right.take();
                pre.borrow_mut().right = right;
                let left = node.borrow_mut().left.take();
                node.borrow_mut().right = left;
            }
            curr = node.borrow().right.clone();
        }
    }
}