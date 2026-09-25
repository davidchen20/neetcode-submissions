class MinStack {
public:
    stack<int> mins;
    stack<int> nums;

    MinStack() {
        
    }
    
    void push(int val) {
        if (mins.empty() || val <= mins.top()) mins.push(val);

        nums.push(val);    
    }
    
    void pop() {
        if (mins.top() == nums.top()) mins.pop();

        nums.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
