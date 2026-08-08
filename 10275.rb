def h_index(citations)
  n = citations.size
  l, r = 0, n - 1
  while l <= r
    m = (l + r) / 2
    citations[m] >= n - m ? r = m - 1 : l = m + 1
  end
  n - l
end