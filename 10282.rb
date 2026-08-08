def add_operators(num, target)
  res = []
  n = num.length

  dfs = lambda do |index, path, eval_val, multed|
    if index == n
      res << path if eval_val == target
      return
    end

    (index...n).each do |i|
      break if num[index] == '0' && i > index
      sub = num[index..i]
      curr = sub.to_i

      if index == 0
        dfs.call(i + 1, sub, curr, curr)
      else
        dfs.call(i + 1, path + "+" + sub, eval_val + curr, curr)
        dfs.call(i + 1, path + "-" + sub, eval_val - curr, -curr)
        dfs.call(i + 1, path + "*" + sub, eval_val - multed + multed * curr, multed * curr)
      end
    end
  end

  dfs.call(0, "", 0, 0)
  res
end