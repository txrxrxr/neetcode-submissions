class Solution {
public:
    int rob(vector<int>& nums) {
        const int N = nums.size();
        std::vector<int> dp(nums.size() + 1); // max money can get at house i
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= N; ++i) {
            dp[i] = std::max(dp[i-1], nums[i - 1] + dp[i-2]);
        }
        return dp.back();
    }
};
