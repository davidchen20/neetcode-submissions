class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) return nums[0];

        int n = nums.size();
        vector<int> memo(n);
        int rob2 = nums[0];
        int rob1 = max(nums[0], nums[1]);
        int rob = rob1;
        for (int i = 2; i < n; i++) {
            // rob house i, we need to come from i-2. if we don't rob i, then we came from i-1
            rob = max(rob2 + nums[i], rob1);
            rob2 = rob1;
            rob1 = rob;
        }

        return rob;
    }
};
