class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefixSums = [0] * len(nums)
        prefixSums[0] = nums[0]
        for i in range(1, len(nums)):
            prefixSums[i] = prefixSums[i-1] * nums[i]

        suffixSums = [0] * len(nums)
        suffixSums[len(nums) - 1] = nums[len(nums) - 1]
        for i in range(len(nums) - 2, -1, -1):
            suffixSums[i] = suffixSums[i+1] * nums[i]

        ans = []

        for i in range(len(nums)):
            prefixSum = 0
            suffixSum = 0
            left = i - 1
            right = i + 1
            if left < 0:
                prefixSum = 1
            else:
                prefixSum = prefixSums[left]
            
            if right > len(nums) - 1:
                suffixSum = 1
            else:
                suffixSum = suffixSums[right]

            ans.append(prefixSum * suffixSum)

        return ans




