class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashMap = dict()

        for i, num in enumerate(nums):
            hashMap[num] = i

        for i, num in enumerate(nums):
            difference = target - num;

            if difference in hashMap and i != hashMap[difference]:
                return [i, hashMap[difference]]
        