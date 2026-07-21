class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window
        if (s.empty())
            return 0;
        
        int i = 0, j = 0;
        int ans = 0;
        const int N = s.size();
        std::unordered_set<int> hs;
        while (i <= j && j < N) {
            if (hs.count(s[j])) {
                // found a duplicate char
                hs.erase(s[i]);
                ++i;
                continue;
            }

            hs.insert(s[j]);
            ans = std::max(ans, j - i + 1);
            ++j;
        }

        return ans;
    }
};
