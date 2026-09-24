class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        partition(nums, 0, nums.size() - 1, nums.size() - k);
        return nums[nums.size() - k];
    }

    void partition(vector<int>& nums, int left, int right, int k) {
        if (left > right) return;
        int pivot = right;

        int l = left;
        int r = right - 1;

        while (l <= r) {
            while (l <= r && nums[l] < nums[pivot]) l++;
            while (l <= r && nums[r] >= nums[pivot]) r--;

            if (l > r) break;

            swap(nums[l], nums[r]);
        }

        swap(nums[l], nums[pivot]);

        if (l == k) return;
        else if (l < k) partition(nums, l + 1, right, k);
        else partition(nums, left, l - 1, k);
    }
};
