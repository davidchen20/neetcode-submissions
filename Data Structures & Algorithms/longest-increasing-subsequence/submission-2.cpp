class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // the max subsequence length given current index and the index before it in the sequence
        vector<int> memo(nums.size(), -1);
        int maxLen = 1;

        for (int i = 0; i < nums.size(); i++) {
            maxLen = max(maxLen, dfs(memo, nums, i));
        }
        
        return maxLen;
    }

    // max length of subsequence starting at index i
    int dfs(vector<int>& memo, vector<int>& nums, int i) {
        if (i == nums.size()) {
            return 0;
        } else {
            if (memo[i] != -1) return memo[i];

            int maxLen = 1;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    maxLen = max(maxLen, 1 + dfs(memo, nums, j));
                }
            }

            memo[i] = maxLen;

            return memo[i];
        }
    }
};
