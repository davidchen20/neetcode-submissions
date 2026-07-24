class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        vector<int> ans;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            heap.push({nums[right], right});
            if (right - left + 1 == k) {
                while (heap.top().second < left) {
                    heap.pop();
                }
                int nextAns = heap.top().first;

                ans.push_back(nextAns);

                left++;
            }
        }

        return ans;
    }
};
