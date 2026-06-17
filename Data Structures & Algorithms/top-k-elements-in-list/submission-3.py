import queue

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashMap = dict()

        for i in range(len(nums)):
            hashMap[nums[i]] = hashMap.get(nums[i], 0) + 1

        pQueue = queue.PriorityQueue()
        for key, value in hashMap.items():
            pQueue.put((value * -1, key))

        ans = []
        for i in range(k):
            ans.append(pQueue.get()[1])
        
        return ans