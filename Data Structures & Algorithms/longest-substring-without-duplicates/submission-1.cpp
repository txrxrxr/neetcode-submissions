class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window
        if (s.empty())
            return 0;
        
        // last seen index
        std::array<int, 128> ls;
        ls.fill(-1);
        
        const int N = s.size();
        int left = 0;
        int ans = 0;
        
        for (int right = 0; right < N; ++right) {
            if (ls[(unsigned char)s[right]] >= left) {
                // found a duplicate char
                left = ls[s[right]] + 1;
                // continue;
            }

            ans = std::max(ans, right - left + 1);
            ls[(unsigned char)s[right]] = right;
        }

        return ans;
    }
};
