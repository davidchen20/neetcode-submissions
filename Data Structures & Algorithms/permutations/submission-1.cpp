class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        unordered_set<int> pathSet;

        dfs(ans, path, pathSet, nums, 0);

        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& path, unordered_set<int>& pathSet, vector<int>& nums, int i) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
        } else {
            for (int j = 0; j < nums.size(); j++) {
                if (!pathSet.count(nums[j])) {
                    path.push_back(nums[j]);
                    pathSet.insert(nums[j]);
                    dfs(ans, path, pathSet, nums, j + 1);
                    pathSet.erase(nums[j]);
                    path.pop_back();
                }
            }
        }
    } 
};
