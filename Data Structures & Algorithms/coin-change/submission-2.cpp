class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end());
        std::vector<int> dp(amount + 1, -2);
        int ans = dfs(coins, amount, dp);
        return ans;
    }

    int dfs(vector<int>& coins, int amount, vector<int>& dp) {
        if (dp[amount] != -2) {
            return dp[amount];
        }

        if (amount == 0) {
            return dp[amount] = 0;
        }

        int cur = 10000 + 1;
        for (const auto c : coins) {
            if (amount - c >= 0) {
                int nxt = dfs(coins, amount - c, dp);
                if (nxt == -1)
                    continue;
                cur = std::min(cur, 1 + nxt);
            } else {
                break;
            }
        }

        if (cur == 10001)
            dp[amount] = -1;
        else
            dp[amount] = cur;
        
        return dp[amount];
    }
};
