def move_zeroes(nums)
  j = 0
  nums.each_with_index do |num, i|
    unless num.zero?
      nums[j], nums[i] = nums[i], nums[j] if i != j
      j += 1
    end
  end
end