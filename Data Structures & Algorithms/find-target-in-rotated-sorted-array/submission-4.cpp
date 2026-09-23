class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        int pivot = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) left = mid + 1;
            else {
                if (nums[mid] < nums[pivot]) pivot = mid;
                right = mid - 1;
            }
        }

        // if (pivot == 0) return binarySearch(nums, 0, nums.size() - 1, target);
        if (target > nums[nums.size()-1]) return binarySearch(nums, 0, pivot - 1, target);
        else return binarySearch(nums, pivot, nums.size() - 1, target);
    }

    int binarySearch(vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;

        int mid = left + (right - left) / 2;

        if (nums[mid] > target) return binarySearch(nums, left, mid - 1, target);
        else if (nums[mid] < target) return binarySearch(nums, mid + 1, right, target);
        else return mid;
    }
};
