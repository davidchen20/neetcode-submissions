class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(), INT_MAX);

        memo[0] = 0;

        // memo[i] = min(memo[k]) + 1 where k < i

        for (int i = 1; i < nums.size(); i++) {
            for (int k = 0; k < i; k++) {
                if (k + nums[k] >= i) memo[i] = min(memo[i], memo[k] + 1);
            }
        }

        return memo[nums.size() - 1];
    }
};
