struct Node {
    Node() : wordEnd(false) {}

    std::unordered_map<char, std::unique_ptr<Node>> next;
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
            if (cur->next.count(c) == 0) {
                cur->next[c] = std::make_unique<Node>();
            }
            cur = cur->next[c].get();
        }
        cur->wordEnd = true;
    }
    
    bool search(const string& word) {
        Node* cur = head.get();
        for (const auto c : word) {
            if (cur->next.count(c) == 0) {
                return false;
            }
            cur = cur->next[c].get();
        }
        return cur->wordEnd;
    }
    
    bool startsWith(string prefix) {
        Node* cur = head.get();
        for (const auto c : prefix) {
            if (cur->next.count(c) == 0) {
                return false;
            }
            cur = cur->next[c].get();
        }
        return true;
    }

    std::unique_ptr<Node> head;
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        PrefixTree t;
        vector<string> ans;
        std::sort(folder.begin(), folder.end());

        for (const auto& f : folder) {
            Node* cur = t.head.get();
            bool isSubFolder = false;
            int idx = 0;
            for (const auto c : f) {
                if (cur->next.count(c) == 0) {
                    cur->next[c] = std::make_unique<Node>();
                }

                cur = cur->next[c].get();

                if (cur->wordEnd && idx + 1 < f.size() && f[idx + 1] == '/') {
                    isSubFolder = true;
                    break;
                }

                ++idx;

            }

            if (isSubFolder) {
                continue;
            }

            cur->wordEnd = true;
            ans.emplace_back(f);
        }

        return ans;
    }
};