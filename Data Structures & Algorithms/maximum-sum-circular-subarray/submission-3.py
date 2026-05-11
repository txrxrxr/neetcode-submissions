class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        # monotonic queue + prefix sum
        ans = nums[0]
        # index of the prefix sum in incresing order
        # ps i to j = ps[j] - ps[i - 1]
        dq = deque([0])
        N = len(nums)
        # when to stop
        # how to use monotonic queue
        #   -1 -2 -3 -1 -2
        # 0 -1 -3 -6 -7 -9
        ps = [0] * (2 * N)
        for i in range(1, 2 * N):
            ps[i] = nums[i % N] + ps[i - 1]
        
        for i in range(1, 2 * N):
            # out of window
            # i - (dq[0] + 1) + 1 > N
            # i - dp[0] > N
            #   1 2 3 4 5
            # 0 1 3 6 10 15
            if i - N > dq[0]:
                dq.popleft()
            ans = max(ans, ps[i] - ps[dq[0]])
            while dq and ps[i] < ps[dq[-1]]:
                dq.pop()
            dq.append(i)

        return ans
