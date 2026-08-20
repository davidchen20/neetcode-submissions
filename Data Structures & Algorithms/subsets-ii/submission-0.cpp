class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;

        sort(nums.begin(), nums.end());

        dfs(nums, ans, path, 0);

        return ans;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, int i) {
        if (i == nums.size()) {
            ans.push_back(path);
            return;
        } else {
            // can include this current number in subset
            path.push_back(nums[i]);
            dfs(nums, ans, path, i + 1);

            // dont include current number in subset
            path.pop_back();
            while (i + 1 < nums.size() && nums[i] == nums[i+1]) i++;
            dfs(nums, ans, path, i + 1);
        }
    }
};
