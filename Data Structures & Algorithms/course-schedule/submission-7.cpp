class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            vector<int>& prereq = prerequisites[i];

            adjList[prereq[0]].push_back(prereq[1]);
        }

        unordered_set<int> visited;
        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(adjList, i, visited)) return false;
        }

        return true;

    }

    bool hasCycle(vector<vector<int>>& adjList, int course, unordered_set<int>& visited) {
        if (visited.count(course)) return true;
        if (adjList[course].empty()) return false;

        visited.insert(course);
        vector<int>& neighbors = adjList[course];
        for (auto neighbor : neighbors) {
            if (hasCycle(adjList, neighbor, visited)) return true;
        }

        visited.erase(course);
        neighbors.clear();
        return false;
    }
};
