class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        vector<vector<int>> frequencies(nums.size()+1);
        for (auto& f : freq) {
            frequencies[f.second].push_back(f.first);
        }

        vector<int> ans(k);
        int index = k - 1;
        for (int i = frequencies.size() - 1; i >= 0; i--) {
            for (int j = 0; j < frequencies[i].size(); j++) {
                ans[index] = frequencies[i][j];
                index--;
                if (index == -1) break;
            }
            if (index == -1) break;
        }

        return ans;
    }
};
