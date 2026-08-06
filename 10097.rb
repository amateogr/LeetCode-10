def is_interleave(s1, s2, s3)
  return false if s1.length + s2.length != s3.length

  n1, n2 = s1.length, s2.length
  dp = Array.new(n2 + 1, false)
  dp[0] = true

  (0..n1).each do |i|
    (0..n2).each do |j|
      next if i == 0 && j == 0
      dp[j] = (i > 0 && dp[j] && s1[i - 1] == s3[i + j - 1]) || (j > 0 && dp[j - 1] && s2[j - 1] == s3[i + j - 1])
    end
  end

  dp[n2]
end