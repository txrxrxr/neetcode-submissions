class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        """
        To aviod hashing collision, each char can multiply by a prime number,
        but this will likly to result in overflow
        """
        # Solution 1: use hash map
        # Time: O(m * nlogn), m = # of strs, n = len of longest str
        # Space: O(m * n)
        hm = defaultdict(list)
        for s in strs:
            hm[''.join(sorted(s))].append(s)
        return list(hm.values())