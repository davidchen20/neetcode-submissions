class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int i = 0; i < nums.size(); i++) add(nums[i]);
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) pq.pop();

        return pq.top();
    }
};
