class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProf = 0
        for i in range(len(prices)):
            boughtPrice = prices[i]
            j = i + 1
            while j < len(prices):
                maxProf = max(prices[j] - boughtPrice, maxProf)
                j += 1

        return maxProf

