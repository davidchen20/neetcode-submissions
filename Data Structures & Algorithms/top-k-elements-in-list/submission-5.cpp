class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> frequencies(nums.size()+1);

        unordered_map<int, int> counts;

        for (auto num : nums) {
            counts[num]++;
        }

        for (auto &item : counts) {
            frequencies[item.second].push_back(item.first);
        }

        vector<int> ans;

        int idx = frequencies.size() - 1;
        while (ans.size() != k) {
            if (!frequencies[idx].empty()) {
                ans.push_back(frequencies[idx].back());
                frequencies[idx].pop_back();
            } else {
                idx--;
            }
        }

        return ans;
    }
};
