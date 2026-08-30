class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        vector<int> memo(nums.size(), -1);
        // you can either choose to rob first one or last one or none
        int opt1 = dfs(memo, nums, 0, nums.size() - 2);

        vector<int> memo1(nums.size(), -1);
        int opt2 = dfs(memo1, nums, 1, nums.size() - 1);

        vector<int> memo2(nums.size(), -1);
        int opt3 = dfs(memo2, nums, 1, nums.size() - 2);
        
        return max(opt1, max(opt2, opt3));
        // return max(dfs(memo, nums, 0, nums.size() - 2), max(dfs(memo, nums, 1, nums.size() - 1), dfs(memo, nums, 1, nums.size() - 2));
    }

    // max money that can be made from index i to right
    // forward recursion
    // i is within [left, right]
    int dfs(vector<int>& memo, vector<int>& nums, int i, int right) {
        if (i > right) return 0;

        if (memo[i] != -1) return memo[i];

        memo[i] = max(nums[i] + dfs(memo, nums, i + 2, right), dfs(memo, nums, i + 1, right));
        return memo[i];
    }
};
