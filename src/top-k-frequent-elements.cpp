import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        if k == len(nums):
            return nums
        
        d = dict()
        
        for num in nums:
            if num in d:
                d[num] += 1
            else:
                d[num] = 1
                    
        return heapq.nlargest(k, d.keys(), key=d.get)
