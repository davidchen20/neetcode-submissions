class Solution {
public:
    struct Comparator {
        float distance(vector<int>& p1) {
            int xDiff = p1[0] - 0;
            int yDiff = p1[1] - 0;

            return xDiff * xDiff + yDiff * yDiff;
        }
        bool operator()(vector<int>& p1, vector<int>& p2) {
            return distance(p1) < distance(p2);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Comparator> pq;

        for (int i = 0; i < points.size(); i++) {
            pq.push(points[i]);
            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};
