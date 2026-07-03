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
        // top-down DP
        // dp[i..end] can be splitted
        // base case: start == s.size()
        // solve the trailing suffix first
        // DP size：s.size()
        std::vector<int> dp(s.size(), -1);
        for (const auto& w : wordDict) {
                t.insert(w);
        }
        return dfs(t, dp, s, 0);
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
