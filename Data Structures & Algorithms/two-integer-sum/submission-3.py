class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        two pointers
        """
        N = len(nums)
        indexed_nums = sorted([(n, i) for i, n in enumerate(nums)])
        i = 0
        j = len(nums) - 1
        while i < j:
            if indexed_nums[i][0] + indexed_nums[j][0] < target:
                i += 1
            elif indexed_nums[i][0] + indexed_nums[j][0] > target:
                j -= 1
            else:
                return sorted([indexed_nums[i][1], indexed_nums[j][1]])
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
        
