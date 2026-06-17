class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashMap = dict()

        for i in range(len(nums)):
            hashMap[nums[i]] = i

        for i in range(len(nums)):
            difference = target - nums[i]

            if difference in hashMap and hashMap.get(difference) != i:
                return [i, hashMap.get(difference)]
        