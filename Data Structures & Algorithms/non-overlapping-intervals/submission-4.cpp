class Solution {
public:
    struct Compare{
        bool operator()(vector<int>& v1, vector<int>& v2) {
            if (v1[1] != v2[1]) return v1[1] < v2[1];
            return v1[0] < v2[0];
        }
    };
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return 0;
        sort(intervals.begin(), intervals.end(), Compare());

        int prevEnd = intervals[0][1];
        int count = 0;
        for (int i = 1; i < intervals.size(); i++) {
            while (i < intervals.size() && intervals[i][0] < prevEnd) {
                count++;
                i++;
            }
            prevEnd = intervals[i][1];
        }

        return count;
    }
};
