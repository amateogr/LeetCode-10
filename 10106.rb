def build_tree(inorder, postorder)
    map = {}
    inorder.each_with_index { |v, i| map[v] = i }
    p = [postorder.size - 1]
    
    helper = lambda do |l, r|
        return nil if l > r
        val = postorder[p[0]]
        p[0] -= 1
        node = TreeNode.new(val)
        idx = map[val]
        node.right = helper.call(idx + 1, r)
        node.left = helper.call(l, idx - 1)
        node
    end
    
    helper.call(0, inorder.size - 1)
end