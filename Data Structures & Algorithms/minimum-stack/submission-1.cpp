class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);

        if (mins.empty() || s.top() <= mins.top()) mins.push(s.top());
    }
    
    void pop() {
        if (s.top() == mins.top()) mins.pop();

        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
private:
    stack<int> s;

    stack<int> mins;
};
