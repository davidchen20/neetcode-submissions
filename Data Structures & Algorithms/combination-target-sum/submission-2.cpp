class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(nums, ans, path, 0, target);

        return ans;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, int i, int target) {
        int sum = 0;
        for (int num : path) {
            sum += num;
        }

        if (sum == target) {
            ans.push_back(path);
            return;
        } else {
            if (i == nums.size() || sum > target) return;

            path.push_back(nums[i]);
            dfs(nums, ans, path, i, target);

            path.pop_back();
            dfs(nums, ans, path, i + 1, target);
        }
    }
};
