class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    std::sort(coins.begin(), coins.end());

    // -2: uncalculated
    // -1: impossible to make this amount
    // >= 0: minimum number of coins needed
    std::vector<int> dp(amount + 1, -2);

    return dfs(coins, amount, dp);
  }

  // 1. State 是什么？
  // dp[i] represents the minimum number of coins needed to make amount i.
  // dp[i] = -1 means amount i cannot be formed.
  // dp[i] = -2 means this state has not been calculated yet.

  // 2. 当前有哪些 Choice？
  // For the current amount, we can choose any coin c <= amount.
  // After choosing coin c, the remaining subproblem is:
  // dfs(amount - c).

  // 3. Transition 是什么？
  // dp[amount] = min(dp[amount], 1 + dp[amount - c])
  // for every valid coin c.
  //
  // In top-down form:
  // dfs(amount) = min(1 + dfs(amount - c))
  // over all coins c where amount - c >= 0.
  //
  // If dfs(amount - c) == -1, that subproblem is impossible,
  // so we skip that choice.

  // 4. Base case 是什么？
  // dp[0] = 0 because we need 0 coins to make amount 0.
  //
  // Memoization base case:
  // if dp[amount] has already been calculated, return it directly.

  // 5. 为什么按这个顺序遍历？
  // This is top-down DP, so there is no explicit iteration order over states.
  // Starting from the target amount, DFS recursively calculates smaller amounts
  // until reaching amount 0.
  //
  // Memoization ensures each amount is calculated at most once.
  //
  // coins is sorted so that when c > amount, we can break early because
  // all following coins will also be too large.

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

        if (nxt == -1) {
          continue;
        }

        cur = std::min(cur, 1 + nxt);
      } else {
        break;
      }
    }

    if (cur == 10001) {
      dp[amount] = -1;
    } else {
      dp[amount] = cur;
    }

    return dp[amount];
  }
};