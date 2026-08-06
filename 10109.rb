def sorted_list_to_bst(head)
    len = 0
    curr = head
    while curr
        len += 1
        curr = curr.next
    end
    @head = head
    helper(0, len - 1)
end

def helper(left, right)
    return nil if left > right
    mid = (left + right) / 2
    left_child = helper(left, mid - 1)
    node = TreeNode.new(@head.val)
    node.left = left_child
    @head = @head.next
    node.right = helper(mid + 1, right)
    node
end