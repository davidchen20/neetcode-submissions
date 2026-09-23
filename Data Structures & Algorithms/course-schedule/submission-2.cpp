class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // detect any cycles
        unordered_map<int, vector<int>> preMap;

        for (auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        // check each course for a cycle
        for (int i = 0; i < numCourses; i++) {
            unordered_set<int> visited;
            if (!dfs(preMap, visited, i)) return false;
        }

        return true;
    }

    bool dfs(unordered_map<int, vector<int>>& preMap, unordered_set<int>& visited, int c) {
        if (visited.count(c)) return false;
        visited.insert(c);
        vector<int>& prereqs = preMap[c];
        for (auto prereq : prereqs) {
            if (!dfs(preMap, visited, prereq)) return false;
        }
        visited.erase(c);
        preMap[c].clear();

        return true;
    }
};
