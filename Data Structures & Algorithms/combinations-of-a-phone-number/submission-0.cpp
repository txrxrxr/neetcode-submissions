class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        
        const std::array<string, 10> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        ans.reserve(digits.size());
        string cur;
        dfs(mapping, digits, ans, cur, 0);
        return ans;
    }

    void dfs(const std::array<string, 10>& mapping, string& digits, vector<string>& ans, string& cur, int idx) {
        if (idx == digits.size()) {
            ans.emplace_back(cur);
            return;
        }

        int n = digits.at(idx) - '0';
        for (auto c : mapping[n]) {
            cur.push_back(c);
            dfs(mapping, digits, ans, cur, idx + 1);
            cur.pop_back();
        }
    }
};
