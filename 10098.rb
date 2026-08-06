def is_valid_bst(root, min = -Float::INFINITY, max = Float::INFINITY)
    return true if root.nil?
    return false if root.val <= min || root.val >= max
    is_valid_bst(root.left, min, root.val) && is_valid_bst(root.right, root.val, max)
end