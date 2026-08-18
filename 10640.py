import re

_TOKEN_REGEX = re.compile(r'[+-]?(?:\d*x|\d+)')


class Solution:

  def solveEquation(self, equation: str) -> str:
    l, r = equation.split('=')

    def parse(s):
      x_coeff = const = 0
      for t in _TOKEN_REGEX.findall(s):
        if 'x' in t:
          x_coeff += (
              1
              if t in ('x', '+x')
              else (-1 if t == '-x' else int(t[:-1]))
          )
        else:
          const += int(t)
      return x_coeff, const

    lx, lc = parse(l)
    rx, rc = parse(r)
    dx, dc = lx - rx, rc - lc
    if dx == 0:
      return 'Infinite solutions' if dc == 0 else 'No solution'
    return f'x={dc // dx}'