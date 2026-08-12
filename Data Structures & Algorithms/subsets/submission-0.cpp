class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, path, nums, ans);

        return ans;
    }

    void dfs(int i, vector<int>& path, const vector<int>& nums, vector<vector<int>>& ans) {
        if (i >= nums.size()) {
            ans.push_back(path);
            return;
        }
        
        path.push_back(nums[i]);
        dfs(i + 1, path, nums, ans);

        path.pop_back();
        dfs(i+1, path, nums, ans);
    }
};
