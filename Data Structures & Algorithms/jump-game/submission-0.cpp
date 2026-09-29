class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> memo(nums.size());

        memo[nums.size() - 1] = true;

        for (int i = nums.size() - 2; i >= 0; i--) {
            int maxJump = nums[i];
            for (int j = 0; j <= maxJump; j++) {
                if (i + j < nums.size()) memo[i] = memo[i] || memo[i + j];
            }
        }

        return memo[0];
    }
};
