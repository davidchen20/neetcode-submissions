class Solution {
public:
    int search(vector<int>& nums, int target) {
        // edge cases
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;

        int left = 0; 
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            // if in Right Sorted
            if (nums[mid] >= nums[left]) {
                // is target within this half?
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // is target within this half?
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
