class TreeNode
    attr_accessor :val, :left, :right
    def initialize(val = 0, left = nil, right = nil)
        @val = val
        @left = left
        @right = right
    end
end

def generate_trees(n)
    return [] if n == 0
    memo = {}
    solve = ->(s, e) {
        return [nil] if s > e
        key = [s, e]
        return memo[key] if memo.key?(key)
        res = []
        (s..e).each do |i|
            solve.call(s, i - 1).each do |l|
                solve.call(i + 1, e).each do |r|
                    res << TreeNode.new(i, l, r)
                end
            end
        end
        memo[key] = res
    }
    solve.call(1, n)
end