class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans = []
        cur_max = float('-inf')
        N = len(nums)
        if N < k:
            for n in nums:
                max = std(max, n)
            ans.append(max)
            return ans
        
        left = 0
        dq = deque()    # max monotonic queue
        for right in range(N):
            # shrink left window
            if right - left + 1 > k:
                cur_max = dq[0]
                if nums[left] == cur_max:
                    dq.popleft()
                left += 1
            
            while dq and dq[-1] < nums[right]:
                dq.pop()
            dq.append(nums[right])
            # print(dq)
            if right - left + 1 == k:
                ans.append(dq[0])
        
        return ans


