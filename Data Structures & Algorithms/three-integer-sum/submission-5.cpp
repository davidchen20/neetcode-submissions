class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int fixed = i;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[fixed] + nums[left] + nums[right];

                if (sum < 0) {
                    int old = nums[left];
                    left++;
                }
                else if (sum > 0) {
                    right--;
                } else {
                    ans.push_back({nums[fixed], nums[left], nums[right]});
                    int old1 = nums[left];
                    int old2 = nums[right];
                    while (nums[left] == old1 && left < right) left++;
                    while (nums[right] == old2 && left < right) right--;
                }
            }
        }

        return ans;
    }
};
