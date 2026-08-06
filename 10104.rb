def max_depth(root)
  root ? 1 + [max_depth(root.left), max_depth(root.right)].max : 0
end