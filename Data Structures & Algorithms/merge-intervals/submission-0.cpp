class Solution {
public:
    struct Compare{
        bool operator()(vector<int>& v1, vector<int>& v2) {
            if (v1[0] != v2[0]) return v1[0] < v2[0];
            return v1[1] < v2[1];
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), Compare());

        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size(); i++) {
            vector<int>& candidate = intervals[i];
            int j = i + 1;
            while (j < intervals.size() && candidate[1] >= intervals[j][0]) {
                candidate[0] = min(candidate[0], intervals[j][0]);
                candidate[1] = max(candidate[1], intervals[j][1]);
                j++;
            }
            ans.push_back(candidate);
            i = j-1;
        }

        return ans;
    }
};
