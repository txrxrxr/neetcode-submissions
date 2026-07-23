class Solution {
public:
    int search(vector<int>& nums, int target) {
        // binary search
        int i = 0, j = nums.size() - 1;

        while (i <= j) {
            int m = i + (j - i) / 2;
            if (target == nums[m])
                return m;
            
            // nums[i..m] is sorted
            if (nums[i] <= nums[m]) {
                if (target < nums[m] && target >= nums[i])
                    j = m - 1;
                else
                    i = m + 1;
            } else if (nums[m] < nums[j]) {
                if (target <= nums[j] && target > nums[m])
                    i = m + 1;
                else
                    j = m - 1;
            }

            // printf("%d %d\n", i , j);
        }

        return -1;
    }
};
