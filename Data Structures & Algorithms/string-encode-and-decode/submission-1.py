class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded = ""
        for i in range(len(strs)):
            encoded += str(len(strs[i])) + ":" + strs[i]

        return encoded

    def decode(self, s: str) -> List[str]:
        ans = []
        while len(s) != 0:
            i = 0
            strLength = ""
            while s[i] != ":":
                i += 1
            strLength = int(s[0:i])
            ans.append(s[i+1:len(str(strLength))+1+strLength])
            s = s[len(str(strLength)) + 1 + strLength:]

        return ans

