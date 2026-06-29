class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1)
            return strs[0];
        
        std::sort(strs.begin(), strs.end());
        std::string ans;
        for (int i = 1; i < strs.size(); ++i) {
            if (i == 1) {
                int minLen = std::min(strs[i].size(), strs[i-1].size());
                int j = 0;
                while (j < minLen) {
                    if (strs[i][j] == strs[i-1][j]) {
                        ans.push_back(strs[i][j]);
                    } else {
                        break;
                    }
                    ++j;
                }
            } else {
                if (ans.empty())
                    return ans;
                int minLen = std::min(strs[i].size(), ans.size());
                int j = 0;
                while (j < minLen) {
                    if (strs[i][j] != ans[j]) {
                        break;
                    }
                    ++j;
                }
                if (j > 0) {
                    ans = ans.substr(0, j);
                }
            }
        }

        return ans;
    }
};