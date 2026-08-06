def level_order(root)
    return [] unless root
    res, curr = [], [root]
    until curr.empty?
        nxt, vals = [], []
        curr.each do |node|
            vals << node.val
            nxt << node.left if node.left
            nxt << node.right if node.right
        end
        res << vals
        curr = nxt
    end
    res
end