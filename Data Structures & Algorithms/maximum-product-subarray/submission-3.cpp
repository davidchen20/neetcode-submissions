class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxMemo(nums.size());
        vector<int> minMemo(nums.size());

        maxMemo[0] = nums[0];
        minMemo[0] = nums[0];

        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // use the min
            int opt1 = nums[i] * minMemo[i-1];
            int opt2 = nums[i] * maxMemo[i-1];
            int opt3 = nums[i];

            maxMemo[i] = max(opt1, max(opt2, opt3));
            minMemo[i] = min(opt1, min(opt2, opt3));

            ans = max(ans, max(opt1, max(opt2, opt3)));
        }

        return ans;
    }
};
