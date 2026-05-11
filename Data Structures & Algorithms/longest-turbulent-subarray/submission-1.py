class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        left, right = 0, 0
        cur_sign = 0  # -1: less, 1: greater
        ans = 0
        if len(arr) < 2:
            return len(arr)
        
        for right in range(1, len(arr)):
            if arr[right] == arr[right - 1]:
                left = right
                cur_sign = 0
            elif cur_sign == -1 and arr[right - 1] < arr[right]:
                left = right - 1
            elif cur_sign == 1 and arr[right - 1] > arr[right]:
                left = right - 1
            ans = max(right - left + 1, ans)
            cur_sign = -1 if arr[right - 1] < arr[right] else 1

        return ans
        