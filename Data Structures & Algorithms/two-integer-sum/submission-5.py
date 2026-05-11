class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        hash map
        what if there are duplicates?
        """
        # hm = {n: i for i, n in enumerate(nums)}
        hm = {}
        for i, n in enumerate(nums):
            x = target - n
            if x in hm.keys():
                return [hm[x], i]
            hm[n] = i
        return []
