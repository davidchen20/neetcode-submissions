class Solution {
public:
    int jump(vector<int>& nums) {
       int count = 0;

       int left = 0;
       int right = 0;

        while (right != nums.size() - 1) {
            int closest = right + 1;
            int furthest = 0;
            for (int i = left; i <= right; i++) {
                furthest = min((int) nums.size() - 1, max(furthest, i + nums[i]));
            }

            left = closest;
            right = furthest;
            count++;
        }

        return count;
    }
};
