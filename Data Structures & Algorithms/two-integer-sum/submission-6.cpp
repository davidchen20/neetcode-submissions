class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];

            if (m.contains(difference) && m[difference] != i) {
                if (i < m[difference]) return {i, m[difference]};
                else return {m[difference], i};
            }
        }

        return {};
    }
};
