class Solution {
public:
    int search(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size() - 1, target);
    }

    int helper(vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;
        int mid = left + (right - left ) / 2;

        if (nums[mid] < target) return helper(nums, mid + 1, right, target);
        else if (nums[mid] > target) return helper(nums, left, mid - 1, target);
        else return mid;
    }
};
