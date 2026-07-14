class Solution {
public:
    int search(vector<int>& nums, int target) {
        // iteratively as well
        int left = 0; 
        int right = nums.size();

        while (left < right) {
            // do it in a way that prevents integer overflow
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid;
            else return mid;
        }

        return -1;
    }
};
