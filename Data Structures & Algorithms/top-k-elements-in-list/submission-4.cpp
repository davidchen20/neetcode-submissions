class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;

        for (auto num : nums) {
            counts[num]++;
        }

        priority_queue<pair<int, int>> pq;

        for (auto &item : counts) {
            pq.push({item.second, item.first});
        }

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            auto item = pq.top();
            pq.pop();
            ans.push_back(item.second);
        }

        return ans;
    }
};
