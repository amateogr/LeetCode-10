def length_of_lis(nums)
  tails = []
  nums.each do |num|
    idx = tails.bsearch_index { |x| x >= num }
    idx ? tails[idx] = num : tails << num
  end
  tails.length
end