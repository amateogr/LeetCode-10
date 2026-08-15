class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        s = s.replace('-', '').upper()
        remainder = len(s) % k
        
        parts = []
        if remainder:
            parts.append(s[:remainder])
        
        for i in range(remainder, len(s), k):
            parts.append(s[i:i + k])
            
        return "-".join(parts)