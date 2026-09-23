class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preMap;
        unordered_set<int> visited;
        unordered_set<int> taken;
        vector<int> ans;

        for (auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(preMap, taken, visited, ans, c)) return { };
        }

        return ans;
    }

    bool dfs(unordered_map<int, vector<int>>& preMap, unordered_set<int>& taken, unordered_set<int>& visited, vector<int>& ans, int c) {
        if (visited.count(c)) return false;

        if (preMap[c].empty()) {
            if (!taken.count(c)) {
                taken.insert(c);
                ans.push_back(c);
            }
            return true;
        }

        visited.insert(c);

        vector<int>& prereqs = preMap[c];
        for (auto prereq : prereqs) {
            if (!dfs(preMap, taken, visited, ans, prereq)) return false;
        }

        visited.erase(c);
        preMap[c].clear();

        if (!taken.count(c)) {
    taken.insert(c);
    ans.push_back(c);
}

        return true;
    }
};
