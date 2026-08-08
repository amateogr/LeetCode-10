def game_of_life(board)
  m, n = board.size, board[0].size
  dirs = [-1, 0, 1].repeated_permutation(2).to_a - [[0, 0]]
  m.times do |r|
    n.times do |c|
      live = dirs.sum { |dr, dc|
        nr, nc = r + dr, c + dc
        nr.between?(0, m - 1) && nc.between?(0, n - 1) ? board[nr][nc] & 1 : 0
      }
      curr = board[r][c] & 1
      board[r][c] |= 2 if (curr == 1 && (live == 2 || live == 3)) || (curr == 0 && live == 3)
    end
  end
  m.times { |r| n.times { |c| board[r][c] >>= 1 } }
end