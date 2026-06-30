class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1)
            return strs[0];
        
        std::sort(strs.begin(), strs.end());
        std::string& s1 = strs.front();
        std::string& s2 = strs.back();
        int minLen = std::min(s1.size(), s2.size());
        int sameUntil = 0;
        for (sameUntil = 0; sameUntil < minLen; ++sameUntil) {
            if (s1[sameUntil] != s2[sameUntil]) {
                break;
            }
        }

        return s1.substr(0, sameUntil);
    }
};