struct Node {
    int key;
    int val;
    std::shared_ptr<Node> nxt;

    Node(int key, int val) : key(key), val(val), nxt(nullptr) {}
};

class MyHashMap {
public:
    MyHashMap() : hm(sz) {
    }
    
    void put(int key, int value) {
        int h = hash(key);
        auto cur = hm[h];
        if (!cur) {
            hm[h] = std::make_shared<Node>(key, value);
            return;
        }

        while (cur) {
            if (cur->key == key) {
                cur->val = value;  // update exisiting value
                return;
            }
            
            if (!cur->nxt)
                break;
            
            cur = cur->nxt;
        }

        cur->nxt = std::make_shared<Node>(key, value);
    }
    
    int get(int key) {
        int h = hash(key);
        auto cur = hm[h];
        while (cur) {
            if (cur->key == key) {
                return cur->val;
            }
                     
            cur = cur->nxt;
        }

        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        auto cur = hm[h];
        std::shared_ptr<Node> prev;
        while (cur) {
            if (cur->key == key) {
                if (prev) {
                    prev->nxt = cur->nxt;
                } else {
                    hm[h] = cur->nxt;
                }
                return;
            }
            prev = cur;  
            cur = cur->nxt;
        }
    }
private:
    int hash(int k) {
        return k % sz;
    }

    static constexpr int sz = 796;
    vector<std::shared_ptr<Node>> hm;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */