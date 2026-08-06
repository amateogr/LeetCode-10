class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res, curr = [], root
        while curr:
            if not curr.left:
                res.append(curr.val)
                curr = curr.right
            else:
                pre = curr.left
                while pre.right and pre.right != curr:
                    pre = pre.right
                if not pre.right:
                    pre.right = curr
                    curr = curr.left
                else:
                    pre.right = None
                    res.append(curr.val)
                    curr = curr.right
        return res