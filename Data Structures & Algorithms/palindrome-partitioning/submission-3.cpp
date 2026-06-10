class Solution {
public:
    vector<vector<string>> partition(string s) {
        // 1. find subsets
        // 2. check if it's palindrome and dfs the check on the rest of the string
        vector<vector<int>> pset;
        pset.resize(s.size(), vector<int>(s.size(), false));
        preCompute(s, pset);
        vector<vector<string>> ans;
        vector<string> cur;
        dfs(s, ans, cur, pset, 0);
        return ans;
    }

    void preCompute(string& s, vector<vector<int>>& pset) {
        int n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && ((j - i) <= 2 || pset[i+1][j-1])) {
                    pset[i][j] = true;
                }
            }
        }
    }

    void dfs(string& s, vector<vector<string>>& ans, vector<string>& cur, vector<vector<int>>& pset, int start) {
        if (start == s.size()) {
            ans.push_back(cur);
            return;
        }

        // s[start..i] -> check palindrom from left to right
        for (int i = start; i < s.size(); ++i) {
            if (pset[start][i]) {
                cur.emplace_back(s.substr(start, i - start + 1));
                dfs(s, ans, cur, pset, i + 1);
                cur.pop_back();
            }
        }        
    }

    bool isPalindrome(std::string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};
