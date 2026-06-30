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

    std::string trimAndFindLCP(const std::string& str) {
        Node* cur = head.get();
        std::string lcp;

        for (int i = 0; i < str.size(); ++i) {
            const auto c = str[i];
            if (!cur || cur->wordEnd) {
                return lcp;
            }

            if (!cur->next[c - 'a']) {
                // delete all the next child nodes
                break;
            } else {
                cur = cur->next[c - 'a'].get();
                lcp.push_back(c);
            }
        }

         // delete all the next child nodes
        for (int i = 0; i < 26; ++i) {
            if (cur->next[i]) {
                cur->next[i].reset();
            }
        }
        cur->wordEnd = true;
        return lcp;
    }

private:
    std::unique_ptr<Node> head;
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1)
            return strs[0];
        
        PrefixTree pt;
        pt.insert(strs.front());
        std::string ans;
        for (int i = 1; i < strs.size(); ++i) {
            ans = pt.trimAndFindLCP(strs[i]);
            if (ans.empty()) {
                break;
            }
        }

       return ans;
    }
};