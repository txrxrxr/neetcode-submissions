#include <print>

// struct vs struct class
// how to use smart pointer here
// how to be thread safe

struct Node {
    Node* prev;
    Node* next;
    int key;
    int val;
    Node() : prev(nullptr), next(nullptr), key(-1), val(-1) {}
    Node(const int key, const int value) : prev(nullptr), next(nullptr), key(key), val(value) {}
};

class LRUCache {
public:
    // utilize double-linked list
    LRUCache(int capacity) : capacity_(capacity) {
        head_ = new Node();
        tail_ = new Node();
        head_->next = tail_;
        tail_->prev = head_;
    }
    
    int get(int key) {
        if (!hm_.contains(key)) {
            return -1;
        }
        int val = hm_[key]->val;
        remove(key);    // remove element from linked list
        put(key, val);   // make it to be most recent accessed cache
        std::print("able to get key {} : {}", key, val);
        return val;
    }
    
    void put(int key, int value) {
        Node* n = nullptr;
        if (hm_.contains(key)) {
            hm_[key]->val = value;
            remove(key);
            n = hm_[key];
        } else {
            n = new Node(key, value);
            hm_[key] = n;
        }
        
        // put it at head
        Node* next = head_->next;
        head_->next = hm_[key];
        hm_[key]->prev = head_;
        hm_[key]->next = next;
        next->prev = hm_[key];
        std::print("append key {} after head", key);

        // remove least recent used one
        if (hm_.size() > capacity_) {
            Node* node_to_rmv = tail_->prev;
            remove(node_to_rmv->key);
            hm_.erase(node_to_rmv->key);
            delete node_to_rmv;
            std::print("removed key {}", key);

        }
    }

    void remove(int key) {
        Node* prev = hm_[key]->prev;
        Node* next = hm_[key]->next;
        prev->next = next;
        next->prev = prev;
    }

private:
    std::unordered_map<int, Node*> hm_; // key -> node
    int capacity_;
    Node* head_;
    Node* tail_;
};


