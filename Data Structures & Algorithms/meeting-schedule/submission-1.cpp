/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    struct Compare {
        bool operator()(Interval& int1, Interval& int2) {
            if (int1.end != int2.end) return int1.end < int2.end;
            return int1.start < int2.start;
        }
    };
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), Compare());

        for (int i = 0; i < intervals.size() - 1; i++) {
            Interval& int1 = intervals[i];
            Interval& int2 = intervals[i+1];

            if (int2.start < int1.end) return false;
        }

        return true;
    }
};
