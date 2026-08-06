def is_symmetric(root)
  return true unless root
  
  stack = [[root.left, root.right]]
  while stack.any?
    left, right = stack.pop
    next if left.nil? && right.nil?
    return false if left.nil? || right.nil? || left.val != right.val
    
    stack.push([left.left, right.right], [left.right, right.left])
  end
  true
end