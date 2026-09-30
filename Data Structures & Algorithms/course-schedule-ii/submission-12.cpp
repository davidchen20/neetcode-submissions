class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            vector<int>& prereq = prerequisites[i];
            adjList[prereq[0]].push_back(prereq[1]);
        }

        vector<int> path;
        unordered_set<int> visited;
        unordered_set<int> taken;

        for (int i = 0; i < numCourses; i++) {
            if (!addCourse(adjList, path, visited, taken, i)) return { };
        }

        return path;
    }

    bool addCourse(vector<vector<int>>& adjList, vector<int>& path, unordered_set<int>& visited, unordered_set<int>& taken, int course) {
        if (taken.count(course)) return true;
        if (visited.count(course)) return false;

        visited.insert(course);

        vector<int>& neighbors = adjList[course];
        // make sure all neighbors are met
        for (auto neighbor : neighbors) {
            if (!addCourse(adjList, path, visited, taken, neighbor)) return false;
        }

        visited.erase(course);
        path.push_back(course);
        taken.insert(course);

        return true;
    }
};
