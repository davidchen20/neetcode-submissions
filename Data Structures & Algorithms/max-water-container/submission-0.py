class Solution:
    def maxArea(self, heights: List[int]) -> int:
        pointerOne = 0
        pointerTwo = len(heights) - 1
        maxVolume = 0
        while pointerOne < pointerTwo:
            volume = min(heights[pointerOne], heights[pointerTwo]) * (pointerTwo - pointerOne)
            maxVolume = max(maxVolume, volume)

            if heights[pointerOne] < heights[pointerTwo]:
                pointerOne += 1
            else:
                pointerTwo -= 1

        return maxVolume