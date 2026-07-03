struct Node {
    Node() : next(26), wordEnd(false) {}

    std::vector<std::unique_ptr<Node>> next;
    bool wordEnd;
};

class PrefixTree {
public:
    PrefixTree() {
        head = std::make_unique<Node>();
    }
    
    void insert(const string& word) {
        Node* cur = head.get();
        for (const auto c : word) {
            if (!cur->next[c - 'a']) {
                cur->next[c - 'a'] = std::make_unique<Node>();
            }
            cur = cur->next[c - 'a'].get();
        }
        cur->wordEnd = true;
    }
    
    bool search(const string& word) {
        Node* cur = head.get();
        for (const auto c : word) {
            if (!cur->next[c - 'a']) {
                return false;
            }
            cur = cur->next[c - 'a'].get();
        }
        return cur->wordEnd;
    }
    
    bool startsWith(string prefix) {
        Node* cur = head.get();
        for (const auto c : prefix) {
            if (!cur->next[c - 'a']) {
                return false;
            }
            cur = cur->next[c - 'a'].get();
        }
        return true;
    }

// private:
    std::unique_ptr<Node> head;
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        PrefixTree t;
        // bottom-up DP
        // dp[i] -> dp[0..i-1] can be splitted
        // base case: start == 0
        // solve the leading prefix first
        // DP size：s.size() + 1
        std::vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (const auto& w : wordDict) {
                t.insert(w);
        }

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && t.search(s.substr(j, i - j))) {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp.back();
    }

    bool dfs(PrefixTree& t, std::vector<int>& dp, const string& s, int start) {
        if (start == s.size()) {
            return true;
        }

        if (!dp[start])
            return dp[start];

        Node* cur = t.head.get();
        for (int i = start; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            if (!cur->next[idx]) {
                break;
            }

            cur = cur->next[idx].get();
            if (cur->wordEnd) {
                if(dfs(t, dp, s, i + 1)) {
                    return dp[start] = 1;
                }
            }
        }

        return dp[start] = 0;
    }
};
