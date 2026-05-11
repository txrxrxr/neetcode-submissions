class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        if len(nums) <= 1:
            return 1
        # index
        i = 0
        j = 0
        # min/max monotonic queue (FIFO)
        minQ = deque() # increasing order
        maxQ = deque()  # decreasing order
        ans = 0
        for j in range(len(nums)):
            while minQ and nums[j] < minQ[-1]:
                minQ.pop()
            while maxQ and nums[j] > maxQ[-1]:
                maxQ.pop()
            minQ.append(nums[j])
            maxQ.append(nums[j])

            if abs(maxQ[0] - minQ[0]) > limit:
                if nums[i] == minQ[0]:
                    minQ.popleft()
                elif nums[i] == maxQ[0]:
                    maxQ.popleft()
                i += 1
            else:
                ans = max(j - i + 1, ans)         
        return ans