class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) maxHeap.push(num);
        else minHeap.push(num);

        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if ((minHeap.size() + maxHeap.size()) % 2 == 0) {
            return (minHeap.top() + maxHeap.top()) / 2.;
        } else {
            if (maxHeap.size() < minHeap.size()) return minHeap.top();
            return maxHeap.top();
        }
    }
};
