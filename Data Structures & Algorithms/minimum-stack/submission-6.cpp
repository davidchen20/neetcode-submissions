class MinStack {
public:
    stack<long long> s;
    long long minSoFar;
    MinStack() {
        
    }
    
    void push(int val) {
        if (s.empty()) {
            minSoFar = val;
            s.push(0);
        } else if (val < minSoFar) {
            s.push(val - minSoFar);
            minSoFar = val;
        } else {
            s.push(val - minSoFar);
        }
    }
    
    void pop() {
        if (s.top() < 0) {
            minSoFar = minSoFar - s.top();
        }
        s.pop();
    }
    
    int top() {
        return s.top() >= 0 ? s.top() + minSoFar : minSoFar;
    }
    
    int getMin() {
        return minSoFar;
    }
};
