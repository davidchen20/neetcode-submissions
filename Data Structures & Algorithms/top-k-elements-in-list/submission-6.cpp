class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;

        for (int i = 0; i < nums.size(); i++) {
            counts[nums[i]]++;
        }

        vector<pair<int, int>> v;
        for (auto& pair : counts) {
            v.push_back({pair.second, pair.first});
        }

        sort(v.begin(), v.end(), greater<>());

        vector<int> ans(k);

        for (int i = 0; i < k; i++) {
            ans[i] = v[i].second;
        }

        return ans;
    }
};
