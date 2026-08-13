class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path;
        vector<vector<int>> ans;

        dfs(nums, path, 0, ans, target);

        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& path, int i, vector<vector<int>>& ans, int target) {
        int pathSum = sum(path);
        if (pathSum <= target && i < nums.size()) {
            if (pathSum == target) {
                ans.push_back(path);
                return;
            } else {
                // include current
                path.push_back(nums[i]);
                dfs(nums, path, i, ans, target);

                // exclude current
                path.pop_back();
                dfs(nums, path, i + 1, ans, target);
            }
        }
    }

    int sum(vector<int>& path) {
        int pathSum = 0;
        for (int i = 0; i < path.size(); i++) {
            pathSum += path[i];
        }

        return pathSum;
    }
};
