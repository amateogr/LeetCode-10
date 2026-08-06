def level_order_bottom(root)
    return [] unless root
    res, queue, i = [], [root], 0
    while i < queue.size
        curr, next_idx = [], queue.size
        while i < next_idx
            node = queue[i]
            i += 1
            curr << node.val
            queue << node.left if node.left
            queue << node.right if node.right
        end
        res << curr
    end
    res.reverse
end