class Solution {
public:
    int findMin(vector<int> &nums) {
        // find the first integer than is less than nums[0]

        int left = 0; 
        int right = nums.size() - 1;

        int minVal = nums[0];
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) left = mid + 1;
            if (nums[mid] <= nums[right]) {
                minVal = min(minVal, nums[mid]);
                right = mid - 1;
            }
        }

        return minVal;
    }
};
