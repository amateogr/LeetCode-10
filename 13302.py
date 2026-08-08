class Solution:
    def validSequence(self, word1: str, word2: str) -> list[int]:
        n, m = len(word1), len(word2)
        
        L = [0] * n
        j = 0
        for i in range(n):
            if j < m and word1[i] == word2[j]:
                j += 1
            L[i] = j
            
        R = [0] * (n + 1)
        j = m - 1
        for i in range(n - 1, -1, -1):
            if j >= 0 and word1[i] == word2[j]:
                R[i] = R[i+1] + 1
                j -= 1
            else:
                R[i] = R[i+1]
                
        is_magic = [False] * n
        for idx in range(n):
            l_val = L[idx-1] if idx > 0 else 0
            r_val = R[idx+1]
            if l_val + r_val >= m - 1:
                is_magic[idx] = True
                
        max_magic = [False] * (n + 1)
        for i in range(n - 1, -1, -1):
            max_magic[i] = max_magic[i+1] or is_magic[i]
            
        seq = []
        changed = False
        last_idx = -1
        
        for k in range(m):
            for i in range(last_idx + 1, n):
                if changed:
                    if word1[i] == word2[k] and R[i+1] >= m - 1 - k:
                        seq.append(i)
                        last_idx = i
                        break
                else:
                    if word1[i] == word2[k]:
                        if R[i+1] >= m - 1 - k or max_magic[i+1]:
                            seq.append(i)
                            last_idx = i
                            break
                    else:
                        if R[i+1] >= m - 1 - k:
                            seq.append(i)
                            last_idx = i
                            changed = True
                            break
            else:
                return []
                
        return seq   