class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        unordered_set<int> s;
        dfs(nums, ans, path, s);

        return ans;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, unordered_set<int>& s) {
        // select one 
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (path.size() > nums.size()) return;
                if (!s.count(nums[i])) {
                    s.insert(nums[i]);
                    path.push_back(nums[i]);
                    dfs(nums, ans, path, s);
                    s.erase(nums[i]);
                    path.pop_back();
                }
            }
        }
    }
};
