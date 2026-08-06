def num_trees(n)
  (1..n).inject(1) { |res, i| res * (n + i) / i } / (n + 1)
end