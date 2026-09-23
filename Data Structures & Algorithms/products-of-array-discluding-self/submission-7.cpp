class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);

        int totalProduct = 1;
        int numZeroes = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) totalProduct *= nums[i];
            else numZeroes++;
        }

        if (numZeroes > 1) {
            return vector<int>(nums.size(), 0);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0 && numZeroes != 0) ans[i] = 0;
            else if (nums[i] == 0) ans[i] = totalProduct;
            else ans[i] = totalProduct / nums[i];
        }

        return ans;
    }
};
