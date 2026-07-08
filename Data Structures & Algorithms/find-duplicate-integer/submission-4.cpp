class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;

        // use floyd to find when fast and slow intersect
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (slow != fast);

        // fast and slow are now at the same point. this point is the same distance from
        // the start of the cycle as the first node in list

        int slow2 = 0;
        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
};
