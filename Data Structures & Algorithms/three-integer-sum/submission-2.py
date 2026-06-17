class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)

        ans = []
        for i in range(len(nums) - 1):
            pointerOne = 0
            pointerTwo = len(nums) - 1
            target = -1 * nums[i]
            pointers = []
            while pointerOne < pointerTwo:
                sumVal = nums[pointerOne] + nums[pointerTwo]
                if sumVal > target:
                    pointerTwo -= 1
                    if pointerTwo == i:
                        pointerTwo -= 1
                elif sumVal < target:
                    pointerOne += 1
                    if pointerOne == i:
                        pointerOne += 1
                else:
                    hasSolution = True
                    if pointerOne != i and pointerTwo != i:
                        pointers.append((pointerOne, pointerTwo))
                    pointerOne += 1
            
            if len(pointers) != 0:
                for j in range(len(pointers)):
                    one, two = pointers[j]
                    threeSum = sorted([-1*target, nums[one], nums[two]])
                    if threeSum not in ans:
                        ans.append(threeSum)

        return ans
            
        
        