class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        hashSet = set()

        for num in nums:
            hashSet.add(num)

        if len(hashSet) != len(nums):
            return True
        return False