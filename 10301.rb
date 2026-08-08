require 'set'

def remove_invalid_parentheses(s)
  valid = ->(str) {
    c = 0
    str.each_byte do |b|
      c += 1 if b == 40
      c -= 1 if b == 41
      return false if c < 0
    end
    c == 0
  }

  current = Set[s]
  loop do
    res = current.select(&valid)
    return res.to_a unless res.empty?

    nxt = Set.new
    current.each do |str|
      str.length.times do |i|
        nxt << str[0...i] + str[i + 1..-1] if str[i] == '(' || str[i] == ')'
      end
    end
    current = nxt
  end
end