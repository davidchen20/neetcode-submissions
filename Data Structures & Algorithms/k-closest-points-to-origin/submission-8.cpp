class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        partition(points, 0, points.size() - 1, k);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }


    int dist(const vector<int>& p1) {
        return p1[0] * p1[0] + p1[1] * p1[1];
    }

    void partition(vector<vector<int>>& points, int left, int right, int k) {
        if (left > right) return;
        int pivot = right;
        int l = left;
        int r = right;
        r--;
        while (l <= r) {
            while (l <= r && dist(points[l]) < dist(points[pivot])) l++;

            while (l <= r && dist(points[r]) >= dist(points[pivot])) r--;

            if (l > r) break;
            swap(points[l], points[r]);
        }

        swap(points[l], points[pivot]);
        if (l == k - 1) return;
        else if (l > k - 1) partition(points, left, l - 1, k);
        else partition(points, l + 1, right, k);
    }
};
