class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(ans, path, nums, 0);

        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& path, vector<int>& nums, int i) {
        if (i == nums.size()) {
            ans.push_back(path);
        } else {
            // take it
            path.push_back(nums[i]);
            dfs(ans, path, nums, i + 1);

            // leave it
            path.pop_back();
            dfs(ans, path, nums, i + 1);
        }
    }
};
