class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        word1Map = dict()
        word2Map = dict()

        for i in range(len(s)):
            word1Map[s[i]] = word1Map.get(s[i], 0) + 1;
            word2Map[t[i]] = word2Map.get(t[i], 0) + 1;

        return word1Map == word2Map;

        