class Solution {
public:
    vector<vector<string>> partition(string s) {
        // 1. find subsets
        // 2. check if it's palindrome and the rest are also pandlindrome
        vector<vector<string>> ans;
        vector<string> cur;
        dfs(s, ans, cur, 0);
        return ans;
    }

    void dfs(string& s, vector<vector<string>>& ans, vector<string>& cur, int start) {
        if (start == s.size()) {
            ans.push_back(cur);
            return;
        }

        // s[i..j]
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                cur.emplace_back(s.substr(start, i - start + 1));
                dfs(s, ans, cur, i + 1);
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
