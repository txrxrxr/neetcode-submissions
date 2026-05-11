class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        hm = {} # index: max len? 
        ans = 0
        for i in nums:
            if i in hm:
                continue
            # left boundary + right boundary + 1
            left = hm.get(i - 1, 0)
            right = hm.get(i + 1, 0)
            len = left + right + 1
            hm[i] = len
            hm[i - left] = len
            hm[i + right] = len
            ans = max(ans, len)
        return ans
        