class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int value) {
        st.emplace_back(value);
        if (minSt.empty() || minSt.back() > value) {
            minSt.emplace_back(value);
        } else {
            minSt.emplace_back(minSt.back());
        }
    }
    
    void pop() {
        minSt.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minSt.back();
    }

private:
    std::vector<int> minSt;
    std::vector<int> st;
};