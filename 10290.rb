def word_pattern(pattern, s)
  words = s.split(' ')
  return false if pattern.size != words.size

  p_to_w = {}
  w_to_p = {}

  pattern.each_char.with_index do |c, i|
    w = words[i]
    return false if (p_to_w[c] && p_to_w[c] != w) || (w_to_p[w] && w_to_p[w] != c)

    p_to_w[c] = w
    w_to_p[w] = c
  end

  true
end