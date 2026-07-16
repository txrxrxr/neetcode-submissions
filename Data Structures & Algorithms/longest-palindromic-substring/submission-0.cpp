#include <print>

class Solution {
public:
    string longestPalindrome(string s) {
        // brute force: check every substring
        // dp[i][j] = true if s[i] == s[j] && dp[i+1, j-1]
        const int N = s.size();
        std::vector<std::vector<int>> dp(N, std::vector<int>(N, 0));
        int maxLen = 1;
        int startIdx = 0;
        for (int i = N-1; i >= 0; --i) {
            for (int j = i; j < N; ++j) {
                if (i == j)
                    dp[i][j] = 1;
                else if (j - i == 1)
                    dp[i][j] = s[i] == s[j] ? 1 : 0;
                else
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]) ? 1 : 0;

                if (dp[i][j] == 1 && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    startIdx = i;
                    // std::println("{} {}", maxLen, startIdx);
                }
            }
        }

        return s.substr(startIdx, maxLen);
    }
};
