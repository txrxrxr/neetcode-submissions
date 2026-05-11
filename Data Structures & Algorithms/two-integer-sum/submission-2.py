class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        sort + binary search
        """
        indexed_nums = sorted([(n, i) for i, n in enumerate(nums)])
        for i in range(len(indexed_nums)):
            idx = self.bs(indexed_nums, target - indexed_nums[i][0], i + 1)
            if idx != -1:
                return sorted([indexed_nums[i][1], idx])
        return []
    
    def bs(self, nums: List[tuple], target: int, start: int) -> int:
        i = start
        j = len(nums) - 1
        while i <= j:
            m = i + (j - i) // 2
            if nums[m][0] == target:
                return nums[m][1]
            elif nums[m][0] < target:
                i = m + 1
            else:
                j = m - 1
        return -1
        
