class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> pathSet(nums.size());

        dfs(ans, path, pathSet, nums);

        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& path, vector<bool>& pathSet, vector<int>& nums) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
        } else {
            for (int j = 0; j < nums.size(); j++) {
                if (!pathSet[j]) {
                    path.push_back(nums[j]);
                    pathSet[j] = true;
                    dfs(ans, path, pathSet, nums);
                    pathSet[j] = false;
                    path.pop_back();
                }
            }
        }
    } 
};
