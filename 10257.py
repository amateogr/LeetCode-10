class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if not root:
            return []
        res, stack = [], [(root, str(root.val))]
        while stack:
            node, path = stack.pop()
            if not node.left and not node.right:
                res.append(path)
            if node.right:
                stack.append((node.right, path + f"->{node.right.val}"))
            if node.left:
                stack.append((node.left, path + f"->{node.left.val}"))
        return res