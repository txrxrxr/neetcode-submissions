class Solution {
 public:
  int numDecodings(string s) {
    std::vector<int> dp(s.size(), -1);
    return dfs(s, 0, dp);
  }

  // 1. State 是什么？
  // dp[i] represents the number of ways to decode the suffix s[i:].
  //
  // The state is determined only by the current starting index i.

  // 2. 当前有哪些 Choice？
  // At index i, we have at most two choices:
  // 1. Decode one digit: s[i], if s[i] != '0'.
  // 2. Decode two digits: s[i:i+2], if the number is between 10 and 26.

  // 3. Transition 是什么？
  // dp[i] = dp[i + 1]                          // take one digit
  //       + dp[i + 2]                          // take two digits, if valid
  //
  // More precisely:
  // dp[i] = dfs(i + 1)
  // If s[i:i+2] is valid:
  // dp[i] += dfs(i + 2)

  // 4. Base case 是什么？
  // If i == s.size():
  //   return 1, because we successfully decoded the entire string.
  //
  // If s[i] == '0':
  //   return 0, because no encoding can start with '0'.

  // 5. 为什么按这个顺序遍历？
  // This is top-down DP with memoization.
  // We start from index 0 and recursively solve smaller suffix problems:
  // i -> i + 1 or i + 2.
  //
  // Memoization ensures that each dp[i] is calculated only once.

  int dfs(string& s, int start, std::vector<int>& dp) {
    if (start >= s.size()) {
      return 1;
    }

    if (s[start] == '0') {
      return 0;
    }

    if (dp[start] != -1) {
      return dp[start];
    }

    // Choice 1: decode one digit
    int ways = dfs(s, start + 1, dp);

    // Choice 2: decode two digits if the value is between 10 and 26
    if (start + 1 < s.size() &&
        (s[start] == '1' ||
         (s[start] == '2' && s[start + 1] <= '6'))) {
      ways += dfs(s, start + 2, dp);
    }

    return dp[start] = ways;
  }
};