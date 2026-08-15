class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(ransomNote) > len(magazine):
            return False
        
        counts = [0] * 26
        for char in magazine:
            counts[ord(char) - 97] += 1
            
        for char in ransomNote:
            idx = ord(char) - 97
            counts[idx] -= 1
            if counts[idx] < 0:
                return False
                
        return True