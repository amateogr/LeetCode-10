class Solution {
    public int rob(TreeNode root) {
        int[] answer = helper(root);
        return Math.max(answer[0], answer[1]);
    }

    private int[] helper(TreeNode node) {
        if (node == null) return new int[2];
        int[] left = helper(node.left);
        int[] right = helper(node.right);
        int[] current = new int[2];
        current[0] = node.val + left[1] + right[1];
        current[1] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        return current;
    }
}