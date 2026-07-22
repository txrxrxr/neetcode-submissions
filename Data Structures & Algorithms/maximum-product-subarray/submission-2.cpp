class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0];
        int curMin = nums[0];
        int ans = curMax;

        for (int i = 1; i < nums.size(); ++i) {
            int tmp = curMin;
            // Both min and max must evaluate ALL THREE possibilities:
            // 1. Start a new subarray here (nums[i])
            // 2. Extend the max subarray (nums[i] * prevMax)
            // 3. Extend the min subarray (nums[i] * curMin) -> Handles double negatives!
            curMin = std::min({nums[i], nums[i] * curMin, nums[i] * curMax});
            curMax = std::max({nums[i], nums[i] * curMax, nums[i] * tmp});
            ans = std::max({ans, curMin, curMax});
        }

        return ans;
    }
};
