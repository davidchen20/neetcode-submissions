class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        // each index is the max you can rob
        vector<int> memo(nums.size(), -1);

        return dfs(memo, nums, 0);
    }

    int dfs(vector<int>& memo, vector<int>& nums, int i) {
        if (i >= nums.size()) return 0;
        if (memo[i] > 0) return memo[i];

        memo[i] = max(nums[i] + dfs(memo, nums, i + 2), dfs(memo, nums, i + 1));
        return memo[i];
    }
};
