def h_index(citations)
  n = citations.length
  counts = Array.new(n + 1, 0)
  citations.each { |c| counts[c >= n ? n : c] += 1 }
  total = 0
  n.downto(0) do |i|
    total += counts[i]
    return i if total >= i
  end
end