class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(), nums.end());

        dfs(ans, path, nums, 0);

        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& path, vector<int>& nums, int i) {
        if (i == nums.size()) {
            ans.push_back(path);
        } else {
            // with nums[i] in
            path.push_back(nums[i]);
            dfs(ans, path, nums, i + 1);

            path.pop_back();
            int newIndex = i + 1;
            while (newIndex < nums.size() && nums[newIndex - 1] == nums[newIndex]) newIndex++;
            dfs(ans, path, nums, newIndex);
        }
    }
};
