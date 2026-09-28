class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) return nums[0];
        if (nums.size() < 3) return max(nums[0], nums[1]);
        int n = nums.size();
        // rob the first house
        vector<int> memo1(n-1);
        memo1[0] = nums[0];
        memo1[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++) {
            memo1[i] = max(memo1[i-2] + nums[i], memo1[i-1]);
        }

        // rob the last house
        vector<int> memo2(n-1);
        memo2[0] = nums[1];
        memo2[1] = max(nums[1], nums[2]);
        for (int i = 2; i < n-1; i++) {
            memo2[i] = max(memo2[i-2] + nums[i+1], memo2[i-1]);
        }

        // rob the none
        // vector<int> memo3(n-2);
        // memo3[0] = nums[1];
        // memo3[1] = max(nums[1], nums[2]);
        // for (int i = 2; i < n - 2; i++) {
        //     memo3[i] = max(memo3[i-2] + nums[i], memo3[i-1]);
        // }

        return max(memo1[n-2], memo2[n-2]);
        
    }
};
