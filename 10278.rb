def first_bad_version(n)
  l, r = 1, n
  while l < r
    m = l + (r - l) / 2
    is_bad_version(m) ? r = m : l = m + 1
  end
  l
end