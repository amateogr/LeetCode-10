use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let mut current = Vec::new();
        Self::dfs(&root, target_sum, &mut current, &mut result);
        result
    }

    fn dfs(
        node: &Option<Rc<RefCell<TreeNode>>>,
        remaining: i32,
        current: &mut Vec<i32>,
        result: &mut Vec<Vec<i32>>,
    ) {
        if let Some(n) = node {
            let node_ref = n.borrow();
            current.push(node_ref.val);
            
            if node_ref.left.is_none() && node_ref.right.is_none() && remaining == node_ref.val {
                result.push(current.clone());
            } else {
                Self::dfs(&node_ref.left, remaining - node_ref.val, current, result);
                Self::dfs(&node_ref.right, remaining - node_ref.val, current, result);
            }
            
            current.pop();
        }
    }
}