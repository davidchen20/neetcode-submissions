class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        pointerOne = 0
        pointerTwo = len(numbers) - 1

        while pointerOne < pointerTwo:
            sumVal = numbers[pointerOne] + numbers[pointerTwo]

            if sumVal < target:
                pointerOne += 1
            elif sumVal > target:
                pointerTwo -= 1
            else:
                break

        return [pointerOne + 1, pointerTwo + 1]
