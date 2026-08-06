def sorted_array_to_bst(nums, left = 0, right = nums.length - 1)
    return nil if left > right
    mid = (left + right) / 2
    TreeNode.new(nums[mid]).tap do |node|
        node.left = sorted_array_to_bst(nums, left, mid - 1)
        node.right = sorted_array_to_bst(nums, mid + 1, right)
    end
end