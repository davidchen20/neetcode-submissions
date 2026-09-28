class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) return nums[0];

        int n = nums.size();
        vector<int> memo(n);
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            memo[i] = max(memo[i-2] + nums[i], memo[i-1]);
        }

        return memo[n-1];
    }
};
