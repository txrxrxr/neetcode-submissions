class Solution {
public:
    int countSubstrings(string s) {
        // 1. find all substrings (?)
        // 2. update dp[i][j] if substring is a palindrome
        // 3. break backtrack if dp[i][j] is not a palindrome

        int cnt = 0;
        std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));
        const int N = s.size();
        
        for (int i = N - 1; i >= 0; --i) {
            for (int j = i; j < N; ++j) {
                if (i == j || ((s[i] == s[j]) && ((j - i == 1) || dp[i+1][j-1] == 1))) {
                    dp[i][j] = 1;
                    ++cnt;
                }
            }
        }

        return cnt;
    }

    // void dfs(string& s, int start, int& cnt, std::vector<std::vector<int>>& dp, const int N) {
    //     if (start == N)
    //         return;
    //     if (N - start == 2) {
    //         dp[i][N - 1] = 1;
    //         ++cnt;
    //         return;
    //     }
    //     if (N - start == 3 && s[start] == s[N - 1]) {
    //         dp[i][N - 1] = 1;
    //         ++cnt;
    //         return;
    //     }
    // }
};
