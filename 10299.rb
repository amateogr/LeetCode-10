def get_hint(secret, guess)
  bulls = 0
  cows = 0
  counts = Array.new(10, 0)

  (0...secret.length).each do |i|
    s = secret.getbyte(i) - 48
    g = guess.getbyte(i) - 48

    if s == g
      bulls += 1
    else
      cows += 1 if counts[s] < 0
      cows += 1 if counts[g] > 0
      
      counts[s] += 1
      counts[g] -= 1
    end
  end

  "#{bulls}A#{cows}B"
end