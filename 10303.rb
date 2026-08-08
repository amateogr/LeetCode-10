class NumArray
  def initialize(nums)
    @p = [0]
    nums.each { |n| @p << @p.last + n }
  end

  def sum_range(left, right)
    @p[right + 1] - @p[left]
  end
end