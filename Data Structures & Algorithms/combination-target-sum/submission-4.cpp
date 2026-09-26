class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(ans, path, nums, 0, target);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& path, vector<int>& nums, int i, int target) {
        int pathSum = sum(path);

        if (pathSum == target) {
            ans.push_back(path);
        } else {
            if (pathSum > target || i >= nums.size()) return;

            // take it
            path.push_back(nums[i]);
            dfs(ans, path, nums, i, target);

            // leave it
            path.pop_back();
            dfs(ans, path, nums, i+1, target);
        }
    }

    int sum(vector<int>& path) {
        int s = 0;
        for (int i = 0; i < path.size(); i++) {
            s += path[i];
        }

        return s;
    }
};
