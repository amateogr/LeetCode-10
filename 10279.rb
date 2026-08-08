def num_squares(n)
  root = Math.sqrt(n).to_i
  return 1 if root * root == n

  temp = n
  temp /= 4 while temp % 4 == 0
  return 4 if temp % 8 == 7

  (1..root).each do |i|
    rem = n - i * i
    r = Math.sqrt(rem).to_i
    return 2 if r * r == rem
  end

  3
end