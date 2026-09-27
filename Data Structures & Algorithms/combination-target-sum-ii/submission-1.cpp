class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        sort(candidates.begin(), candidates.end());

        dfs(ans, path, candidates, 0, target);

        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& path, vector<int>& candidates, int i, int target) {
        int pathSum = sum(path);

        if (pathSum == target) {
            ans.push_back(path);
        } else {
            if (i == candidates.size() || pathSum > target) return;

            // do we want this value, or do we want to skip it?
            path.push_back(candidates[i]);
            dfs(ans, path, candidates, i + 1, target);

            path.pop_back();
            int newNumberIndex = i + 1;
            while (newNumberIndex < candidates.size() && candidates[newNumberIndex-1] == candidates[newNumberIndex]) newNumberIndex++;
            dfs(ans, path, candidates, newNumberIndex, target);
        }
    }

    int sum(vector<int>& vec) {
        int s = 0;
        for (auto v : vec) {
            s += v;
        }

        return s;
    }
};
