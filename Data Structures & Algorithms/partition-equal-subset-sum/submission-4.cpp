class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;

        if (sum % 2 != 0) return false;

        int half = sum / 2;
        
        // memo[i] = memo[half - nums[j]]
        // memo[i] = is it possible to get i from the numbers we have
        vector<bool> memo(half + 1);
        memo[0] = true;

        for (int i = 0; i < nums.size(); i++) {
            for (int target = half; target >= 0; target--) {
                if (!memo[target] && target >= nums[i]) memo[target] = memo[target - nums[i]];
            }
        }

        return memo[half];
    }
};
