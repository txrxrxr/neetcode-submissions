#include <print>

// struct vs struct class
// how to use smart pointer here
// how to be thread safe

// struct Node {
//     Node* prev;
//     Node* next;
//     int key;
//     int val;
//     Node() : prev(nullptr), next(nullptr), key(-1), val(-1) {}
//     Node(const int key, const int value) : prev(nullptr), next(nullptr), key(key), val(value) {}
// };

class LRUCache {
public:
    // utilize double-linked list
    LRUCache(int capacity) : capacity_(capacity) {
        // head_ = new Node();
        // tail_ = new Node();
        // head_->next = tail_;
        // tail_->prev = head_;
    }
    
    int get(int key) {
        auto it = hm_.find(key);
        if (it == hm_.end()) {
            return -1;
        }
        int val = hm_[key]->second;
        caches_.splice(caches_.begin(), caches_, it->second);
        // std::print("able to get key {} : {}", key, val);
        return val;
    }
    
    void put(int key, int value) {
        auto it = hm_.find(key);
        if (it != hm_.end()) {
            hm_[key]->second = value;
            caches_.splice(caches_.begin(), caches_, it->second);
        } else {
            // put it at head
            caches_.emplace_front(key, value);
            hm_[key] = caches_.begin();
        }

        // evict least recent used cache
        if (hm_.size() > capacity_) {
            hm_.erase(caches_.back().first);
            caches_.pop_back();
            // std::print("removed key {}", key);
        }
    }

private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> hm_; // key -> node
    std::list<std::pair<int, int>> caches_;
    int capacity_;
};


