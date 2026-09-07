class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;

        for (int i = 0; i < nums.size(); i++) {
            counts[nums[i]]++;
        }
        vector<vector<int>> freq(nums.size());

        for (auto& pair : counts) {
            auto frequency = pair.second - 1;
            auto val = pair.first;

            freq[frequency].push_back(val);
        }

        vector<int> ans;
        
        for (int i = freq.size() - 1; i >= 0; i--) {
            for (int j = 0; j < freq[i].size(); j++) {
                ans.push_back(freq[i][j]);
                if (ans.size() == k) return ans;
            }
        }

        return ans;
    }
};
