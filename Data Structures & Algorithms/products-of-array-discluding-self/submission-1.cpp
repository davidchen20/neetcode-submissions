class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int productOfAll = 1;
        int numZeroes = 0;
        for (auto num : nums) {
            if (num != 0) productOfAll *= num;
            else numZeroes++; 
        }

        if (numZeroes > 1) {
            vector<int> ans(nums.size(), 0);
            return ans;
        }

        vector<int> ans(nums.size(), productOfAll);

        for (int i = 0; i < ans.size(); i++) {
            if (numZeroes > 0 && nums[i] != 0) {
                ans[i] = 0;
            } else if (nums[i] == 0) {
                continue;
            } else {
                ans[i] /= nums[i];
            }
        }

        return ans;
    }
};
