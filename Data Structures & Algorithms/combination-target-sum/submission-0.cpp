class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(0, nums, path, ans, target);
        return ans;
    }

    void dfs(int i, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans, int target) {
        if (sum(path) == target) {
            ans.push_back(path);
            return;
        }
        
        if (i >= nums.size() || sum(path) > target) {
            return;
        } else {
            path.push_back(nums[i]);
            dfs(i, nums, path, ans, target);

            path.pop_back();
            dfs(i + 1, nums, path, ans, target);
        }
    }

    int sum(vector<int>& path) {
        int sum = 0;
        for (int i = 0; i < path.size(); i++) sum += path[i];

        return sum;
    }
};
