class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // make sure we don't pick duplicates
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> path;

        dfs(candidates, ans, path, 0, target);

        return ans;
    }

    void dfs(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& path, int i, int target) {
        int sum = 0;
        for (int num : path) {
            sum += num;
        }

        if (sum == target) {
            ans.push_back(path);
            return;
        } else {
            if (i >= candidates.size() || sum > target) return;
            path.push_back(candidates[i]);
            dfs(candidates, ans, path, i + 1, target);

            path.pop_back();
            int next = i;
            while (next < candidates.size() && candidates[next] == candidates[i]) next++;
            dfs(candidates, ans, path, next, target);
        }
    }
};
