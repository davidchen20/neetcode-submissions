class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // keep a total sum

        // make sure it is even so it can be split

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) return false;
        if (nums.size() < 2) return false;

        

        // memo[i][j] means can i get i more to my sum if im at index j
        vector<vector<int>> memo(sum + 1, vector<int>(nums.size(), -1));
        if (dfs(memo, nums, 0, 0, sum / 2.)) return true;

        return false;
    }

    bool dfs(vector<vector<int>>& memo, vector<int>& nums, int i, int sum, int target) {
        if (sum == target) return true;
        if (i == nums.size() || sum > target) return false;

        if (memo[target-sum][i] != -1) return memo[target-sum][i];

        // include
        bool opt1 = dfs(memo, nums, i + 1, sum + nums[i], target);

        // exclude
        bool opt2 = dfs(memo, nums, i + 1, sum, target);

        memo[target-sum][i] = opt1 || opt2;

        return memo[target-sum][i];
    
    }
};
