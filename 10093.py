class Solution:
    def restoreIpAddresses(self, s: str) -> list[str]:
        res = []
        
        def backtrack(i, path):
            if len(path) == 4:
                if i == len(s):
                    res.append(".".join(path))
                return
            
            remaining_chars = len(s) - i
            remaining_parts = 4 - len(path)
            
            if remaining_chars < remaining_parts or remaining_chars > 3 * remaining_parts:
                return
            
            for j in range(1, 4):
                if i + j > len(s):
                    break
                
                part = s[i:i+j]
                
                if (len(part) > 1 and part[0] == '0') or int(part) > 255:
                    continue
                
                path.append(part)
                backtrack(i + j, path)
                path.pop()
                
        backtrack(0, [])
        return res