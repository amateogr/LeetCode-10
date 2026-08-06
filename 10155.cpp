class MinStack {
    std::vector<int> s;
    std::vector<int> min_s;
public:
    MinStack() {
        s.reserve(30000);
        min_s.reserve(30000);
    }
    
    void push(int val) {
        s.push_back(val);
        if (min_s.empty() || val <= min_s.back()) {
            min_s.push_back(val);
        }
    }
    
    void pop() {
        if (s.back() == min_s.back()) {
            min_s.pop_back();
        }
        s.pop_back();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return min_s.back();
    }
};