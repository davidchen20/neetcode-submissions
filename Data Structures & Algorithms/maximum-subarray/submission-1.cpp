class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // two arrays

        int maxSum = nums[0];
        int currentSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currentSum = max(currentSum + nums[i], nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;

    }
};
