class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector<int> dp(cost.size() + 1);   // dp[i]: min cost to reach ith floor
        dp[0] = 0;
        dp[1] = 0;
        int ans = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        
        return dp.back();
    }
};
