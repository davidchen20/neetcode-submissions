class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // treat it as a linked list
        // find the cycle
        int slow = 0;
        int fast = 0;

        slow = nums[slow];
        fast = nums[nums[fast]];

        while (slow != fast) {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }

        slow = 0;
        while (slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }

        return fast;
    }
};
