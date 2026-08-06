def build_tree(preorder, inorder)
  @p = 0
  @map = inorder.each_with_index.to_h
  build(preorder, 0, inorder.length - 1)
end

def build(preorder, left, right)
  return nil if left > right

  val = preorder[@p]
  @p += 1
  node = TreeNode.new(val)
  idx = @map[val]

  node.left = build(preorder, left, idx - 1)
  node.right = build(preorder, idx + 1, right)

  node
end