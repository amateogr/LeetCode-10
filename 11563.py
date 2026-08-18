class Solution:
    def stoneGameV(self, stoneValue: list[int]) -> int:
        n = len(stoneValue)
        if n == 1:
            return 0
            
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i+1] = prefix[i] + stoneValue[i]
            
        max_l = [[0] * n for _ in range(n)]
        max_r = [[0] * n for _ in range(n)]
        
        for i in range(n):
            max_l[i][i] = max_r[i][i] = stoneValue[i]
            
        m = list(range(n))
        res = 0
        
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                total = prefix[j+1] - prefix[i]
                
                while (prefix[m[i]+1] - prefix[i]) * 2 < total:
                    m[i] += 1
                    
                mid = m[i]
                L_sum = prefix[mid+1] - prefix[i]
                
                res = 0
                if L_sum * 2 == total:
                    res = max_l[i][mid]
                    if max_r[mid+1][j] > res:
                        res = max_r[mid+1][j]
                else:
                    if mid > i:
                        res = max_l[i][mid-1]
                    if mid < j and max_r[mid+1][j] > res:
                        res = max_r[mid+1][j]
                        
                val = res + total
                
                if max_l[i][j-1] > val:
                    max_l[i][j] = max_l[i][j-1]
                else:
                    max_l[i][j] = val
                    
                if max_r[i+1][j] > val:
                    max_r[i][j] = max_r[i+1][j]
                else:
                    max_r[i][j] = val
                    
        return res