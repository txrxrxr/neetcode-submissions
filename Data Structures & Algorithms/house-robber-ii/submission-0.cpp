class Solution {
public:
    int rob(vector<int>& nums) {
        return std::max(helper(nums, 0), helper(nums, 1));
    }

    int helper(const vector<int>& nums, int start) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        
        const int N = nums.size() - 1;
        std::vector<int> dp(N + 1); // max money can get at house i

        dp[0] = 0;
        dp[1] = nums[start];
        for (int i = 2; i <= N; ++i) {
            dp[i] = std::max(dp[i - 1], nums[start + i - 1] + dp[i - 2]);
        }
        return dp.back();
    }

};
