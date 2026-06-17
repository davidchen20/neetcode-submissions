class Solution {
public:
    int search(vector<int>& nums, int target) {
        return searchHelper(nums, 0, nums.size() - 1, target);
    }

    int searchHelper(vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;
        int middle = (left + right) / 2;

        if (nums[middle] > target) return searchHelper(nums, left, middle-1, target);
        else if (nums[middle] < target) return searchHelper(nums, middle + 1, right, target);
        else return middle;
    }
};
