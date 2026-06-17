class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];

            if (m.find(difference) != m.end()) {
                if (i < m[difference]) return {i, m[difference]};
                else return {m[difference], i};
            } else {
                m.insert({nums[i], i});
            }
        }

        return {};
    }
};
