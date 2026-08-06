public class BSTIterator {
    private readonly Stack<TreeNode> _stack = new Stack<TreeNode>();

    public BSTIterator(TreeNode root) {
        PushLeft(root);
    }
    
    public int Next() {
        var curr = _stack.Pop();
        PushLeft(curr.right);
        return curr.val;
    }
    
    public bool HasNext() {
        return _stack.Count > 0;
    }

    private void PushLeft(TreeNode node) {
        while (node != null) {
            _stack.Push(node);
            node = node.left;
        }
    }
}