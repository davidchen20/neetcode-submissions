class MinStack {
public:
    stack<int> s1;
    stack<int> mins;
    MinStack() {}
    
    void push(int val) {
        s1.push(val);
        if (mins.empty() || val <= mins.top()) mins.push(val);
    }
    
    void pop() {
        if (s1.top() == mins.top()) {
            mins.pop();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
