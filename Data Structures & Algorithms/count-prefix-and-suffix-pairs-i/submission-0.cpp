class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        // std::sort(words.begin(), words.end());
        int ans = 0;

        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (isPrefixSuffix(words[i], words[j])) {
                    ++ans;
                }
            }
        }

        return ans;
    }

    bool isPrefixSuffix(std::string& w1, std::string& w2) {
        int l1 = w1.size();
        int l2 = w2.size();
        
        if (l1 > l2) {
            return false;
        }

        for (int i = 0; i < l1; ++i) {
            if (w1[i] != w2[i] || w1[l1 - 1 - i] != w2[l2 - 1 - i]) {
                return false;
            }
        }

        return true;
    }
};