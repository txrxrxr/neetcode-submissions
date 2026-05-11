class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        # monotonic queue + prefix sum
        ans = nums[0]
        dq = deque([0])    # use queue to track min prefix sum within the window
        N = len(nums)
        # [left, right)
        # when to stop
        # how to use monotonic queue
        #   -1 -2 -3 -1 -2
        # 0 -1 -3 -6 -7 -9
        ps = [0] * (2 * N)
        for i in range(1, 2 * N):
            ps[i] = nums[i % N] + ps[i - 1]
        
        for i in range(1, 2 * N):
            # out of window
            if dq[0] < i - N:
                dq.popleft()
            ans = max(ans, ps[i] - ps[dq[0]])
            while dq and ps[i] < ps[dq[-1]]:
                dq.pop()
            dq.append(i)

        return ans
