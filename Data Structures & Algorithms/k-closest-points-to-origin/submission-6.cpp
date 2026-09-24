class Solution {
public:
    struct DistanceCompare {
        // is p1 lower priority than p2
        bool operator()(vector<int>& p1, vector<int>& p2) {
            double dist1 = p1[0] * p1[0] + p1[1] * p1[1];
            double dist2 = p2[0] * p2[0] + p2[1] * p2[1];

            return dist1 < dist2;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, DistanceCompare> pq;

        for (int i = 0; i < points.size(); i++) {
            pq.push(points[i]);

            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};
