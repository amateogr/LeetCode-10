def find_duplicate(nums)
  slow = nums[0]
  fast = nums[0]
  loop do
    slow = nums[slow]
    fast = nums[nums[fast]]
    break if slow == fast
  end
  slow = nums[0]
  while slow != fast
    slow = nums[slow]
    fast = nums[fast]
  end
  slow
end