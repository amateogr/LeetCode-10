def serialize(root)
  res = []
  dfs = ->(node) do
    if node
      res << node.val
      dfs[node.left]
      dfs[node.right]
    else
      res << 'N'
    end
  end
  dfs[root]
  res.join(',')
end

def deserialize(data)
  vals = data.split(',')
  i = 0
  build = -> do
    v = vals[i]
    i += 1
    return nil if v == 'N' || v.nil?
    
    node = TreeNode.new(v.to_i)
    node.left = build[]
    node.right = build[]
    node
  end
  build[]
end