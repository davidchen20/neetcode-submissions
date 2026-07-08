class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                // Mark it as seen
                nums[index] *= -1;
            } else {
                return abs(nums[i]);
            }
        }

        return 0;
    }
};
