class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        N = len(arr)
        if N < 2:
            return N
        ans = 1
        prev_sign = 0 # 1: <, 2: >
        l, r = 0, 0
        for r in range(1, len(arr)):
            if arr[r-1] == arr[r]:
                l = r
                prev_sign = 0
                continue
                
            curr_sign = 1 if arr[r-1] < arr[r] else 2
            if prev_sign != 0 and curr_sign == prev_sign:
                l = r - 1
                
            prev_sign = curr_sign
            ans = max(r - l + 1, ans)
        
        return ans