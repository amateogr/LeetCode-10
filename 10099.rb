def recover_tree(root)
  first = nil
  second = nil
  prev = nil
  curr = root
  while curr
    if curr.left
      pre = curr.left
      pre = pre.right while pre.right && pre.right != curr
      if pre.right.nil?
        pre.right = curr
        curr = curr.left
      else
        pre.right = nil
        if prev && prev.val > curr.val
          first ||= prev
          second = curr
        end
        prev = curr
        curr = curr.right
      end
    else
      if prev && prev.val > curr.val
        first ||= prev
        second = curr
      end
      prev = curr
      curr = curr.right
    end
  end
  first.val, second.val = second.val, first.val if first && second
  root
end