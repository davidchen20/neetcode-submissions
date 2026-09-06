class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size() + 1, -1));
        vector<int> path;

        return dfs(memo, nums, 0, -1);
    }

    int dfs(vector<vector<int>>& memo, vector<int>& nums, int i, int prev) {
        if (i == nums.size()) {
            return 0;
        } else {
            if (memo[i][prev + 1] != -1) return memo[i][prev + 1];

            int opt1 = 0;
            int opt2 = 0;

            if (prev == -1 || nums[i] > nums[prev]) {
                opt1 = 1 + dfs(memo, nums, i + 1, i);
            }

            opt2 = dfs(memo, nums, i + 1, prev);

            memo[i][prev + 1] = max(opt1, opt2);

            return memo[i][prev + 1];
        }
    }
};
