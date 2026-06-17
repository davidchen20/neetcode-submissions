class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];

            auto res = map.find(difference);
            if (res == map.end()) continue;

            if (res->second != i) return { i, res->second };
            
        }

        return {0};
    }
};
