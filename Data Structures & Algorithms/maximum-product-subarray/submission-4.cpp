class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 2 4 3 -5 2 2 2 -6
        
        // maxProduct = {2, 8, -3, 5}
        // minProduct = {2, 2, -24, -120}

        // maxProduct[i] = max(nums[i] * minProduct[i-1], max(nums[i] * maxProduct, nums[i]));
        // minProduct[i] = min(nums[i] * maxProduct[i-1], min(nums[i] * minProduct, nums[i]));

        vector<int> maxProduct(nums.size());
        vector<int> minProduct(nums.size());

        maxProduct[0] = nums[0];
        minProduct[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maxProduct[i] = max(nums[i] * minProduct[i-1], max(nums[i] * maxProduct[i-1], nums[i]));
            minProduct[i] = min(nums[i] * minProduct[i-1], min(nums[i] * maxProduct[i-1], nums[i]));
        }

        int maxVal = nums[0];
        for (int i = 0; i < maxProduct.size(); i++) {
            maxVal = max(maxVal, maxProduct[i]);
        }

        return maxVal;
    }
};
