class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        """
        To aviod hashing collision, each char can multiply by a prime number,
        but this will likly to result in overflow
        """
        # Solution 2: use hash map
        # Time: O(m * n), m = # of strs, n = len of longest str
        # Space: O(m * n)
        # hm key needs to be immutable
        hm = defaultdict(list)
        for s in strs:
            cnt = [0] * 26
            for c in s:
                cnt[ord(c) - ord('a')] += 1
            hm[tuple(cnt)].append(s)
        return list(hm.values())