class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        // search vertically by column
        int lcp = 0;
        for (int c = 0; c < strs[0].size(); ++c) {
            for (int r = 1; r < strs.size(); ++r) {
                if (c >= strs[r].size() || strs[r][c] != strs[0][c]) {
                    return strs[0].substr(0, c);
                }
            }
        }

        return strs[0];
    }
};