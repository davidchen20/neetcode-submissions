class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());

        vector<int> prefix(nums.size() + 1, 1);
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = nums[i] * prefix[i];
        }

        vector<int> suffix(nums.size() + 1, 1);
        for (int i = nums.size()-1; i >= 0; i--) {
            suffix[i] = nums[i] * suffix[i+1];
        }

        for (int i = 0; i < ans.size(); i++) {
            ans[i] = prefix[i] * suffix[i+1];
        }

        return ans;
    }
};
