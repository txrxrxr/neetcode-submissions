class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        """
        hashing: each char c in ascii x 10^i where i the indx of char in the sorted char array
        """
        hm = defaultdict(list)
        for s in strs:
            hm[''.join(sorted(s))].append(s)
        return list(hm.values())