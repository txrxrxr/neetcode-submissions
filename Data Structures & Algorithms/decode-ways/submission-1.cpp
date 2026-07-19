class Solution {
public:
    int numDecodings(string s) {
        int ans = 0;
        std::vector<int> dp(s.size(), -1);
        dfs(s, 0, ans, dp);
        return dp[0] > 0 ? dp[0] : 0;
    }

    int dfs(string& s, int start, int& ans, std::vector<int>& dp) {
        if (start >= s.size()) {
            return 1;
        }

        if (s[start] == '0') {
            return 0;
        }

        if (dp[start] != -1) {
            return dp[start];
        }

        int ways = dfs(s, start + 1, ans, dp);
        if (start < s.size() - 1 && 
                (s[start] == '1' || (s[start] == '2' && s[start+1] >= '0' && s[start+1] <= '6'))) {
            ways += dfs(s, start + 2, ans, dp);
        }
        dp[start] = ways;
        return ways;
    }
};
