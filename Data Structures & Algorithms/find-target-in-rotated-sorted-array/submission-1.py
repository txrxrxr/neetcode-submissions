class Solution:
    def search(self, nums: List[int], target: int) -> int:
        """
        binary search
        """
        l = 0
        r = len(nums) - 1
        while l <= r:
            m = l + (r - l) // 2
            if nums[m] == target:
                return m
            if nums[l] <= nums[m]:
                # left part is sorted
                if target >= nums [l] and target < nums[m]:
                    r = m - 1
                else:
                    l = m + 1
            else:
                if target > nums[m] and target <= nums[r]:
                    l = m + 1
                else:
                    r = m - 1
        return -1
