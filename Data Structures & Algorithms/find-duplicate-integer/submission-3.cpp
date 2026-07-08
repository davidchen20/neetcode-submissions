class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            // Find the index (e.g. 1 -> 0, 5 -> 4) of the current number
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                // Mark the corresponding index as seen
                nums[index] *= -1;
            } else {
                return abs(nums[i]);
            }
        }

        return 0;
    }
};
