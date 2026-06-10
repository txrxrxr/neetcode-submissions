#include <print>

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        vector<string> ans;
        std::string cur;
        dfs(open, close, n, ans, cur);
        return ans;
    }

    void dfs(int open, int close, int n, vector<string>& ans, std::string& cur) {
        if (open == n && close == n) {
            std::print("{}", cur);
            ans.push_back(cur);
            return;
        }

        if (open < n) {
            cur.append("(");
            dfs(open + 1, close, n, ans, cur);
            cur.pop_back();
        }
        
        if (close < open) {
            cur.append(")");
            dfs(open, close + 1, n, ans, cur);
            cur.pop_back();
        }
    }
};
