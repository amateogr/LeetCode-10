class NumMatrix
  def initialize(matrix)
    return if matrix.empty? || matrix[0].empty?
    m = matrix.length
    n = matrix[0].length
    @dp = Array.new(m + 1) { Array.new(n + 1, 0) }
    for i in 0...m
      for j in 0...n
        @dp[i + 1][j + 1] = matrix[i][j] + @dp[i][j + 1] + @dp[i + 1][j] - @dp[i][j]
      end
    end
  end

  def sum_region(row1, col1, row2, col2)
    @dp[row2 + 1][col2 + 1] - @dp[row1][col2 + 1] - @dp[row2 + 1][col1] + @dp[row1][col1]
  end
end