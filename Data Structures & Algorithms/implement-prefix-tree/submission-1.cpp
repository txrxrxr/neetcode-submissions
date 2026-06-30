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

private:
    std::unique_ptr<Node> head;
};
