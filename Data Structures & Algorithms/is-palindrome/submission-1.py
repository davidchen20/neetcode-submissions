class Solution:
    def isPalindrome(self, s: str) -> bool:
        lowered = s.lower()
        condensed = ""
        for i in range(len(s)):
            if lowered[i].islower() or lowered[i].isdigit():
                condensed += lowered[i]

        
        pointerOne = 0
        pointerTwo = len(condensed) - 1

        while pointerOne < pointerTwo:
            point1 = condensed[pointerOne]
            point2 = condensed[pointerTwo]
            if condensed[pointerOne] != condensed[pointerTwo]:
                return False
            pointerOne += 1
            pointerTwo -= 1
        return True