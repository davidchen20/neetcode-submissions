class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) < 1:
            return len(s)
        l, r = 0, 1

        maxLen = 1
        hashSet = set()
        hashSet.add(s[l])
        while r < len(s):
            while s[r] in hashSet:
                hashSet.remove(s[l])
                l += 1
            hashSet.add(s[r])
            
            maxLen = max(maxLen, len(hashSet))
            r += 1
           
                
        return maxLen