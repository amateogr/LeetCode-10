def zigzag_level_order(root)
  return [] unless root
  res = []
  curr = [root]
  ltr = true

  until curr.empty?
    vals = curr.map(&:val)
    res << (ltr ? vals : vals.reverse)
    curr = curr.flat_map { |n| [n.left, n.right] }.compact
    ltr = !ltr
  end

  res
end