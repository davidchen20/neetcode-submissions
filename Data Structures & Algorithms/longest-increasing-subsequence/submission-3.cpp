class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 9 1 4 2 3 3 7

        // 9
        // 1
        // 1 4
        // 1 4

        // 1 2 3
        // 1 2 3
        // 1 2 3 7

        // have a memo where it is the max increasing sequence htat includes that number up to that number
        // memo[i] = max(1+memo[k]) where nums[i] > nums[k]

        vector<int> memo(nums.size(), 1);
        memo[0] = 1;

        int maxLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int k = 0; k < i; k++) {
                if (nums[i] > nums[k]) {
                    memo[i] = max(memo[i], memo[k] + 1);
                    maxLen = max(maxLen, memo[i]);
                }
            }
        }

        return maxLen;
    } 
};
