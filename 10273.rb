def number_to_words(num)
  return "Zero" if num == 0

  lt20 = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
  tens = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
  thousands = ["", "Thousand", "Million", "Billion"]

  parse = lambda do |n|
    case n
    when 0 then ""
    when 1..19 then lt20[n]
    when 20..99 then [tens[n / 10], parse.call(n % 10)].reject(&:empty?).join(" ")
    else [lt20[n / 100], "Hundred", parse.call(n % 100)].reject(&:empty?).join(" ")
    end
  end

  parts = []
  i = 0
  while num > 0
    rem = num % 1000
    if rem > 0
      w = parse.call(rem)
      th = thousands[i]
      parts.unshift([w, th].reject(&:empty?).join(" "))
    end
    num /= 1000
    i += 1
  end

  parts.join(" ")
end