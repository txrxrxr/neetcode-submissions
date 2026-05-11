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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() < 2) {
            return true;
        }
        std::sort(intervals.begin(), intervals.end(), 
            [](const Interval& i1, const Interval& i2) {
                return (i1.start == i2.start) ? (i1.end < i2.end) : (i1.start < i2.start);
            });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i-1].end)
                return false;
        }
        return true;
    }
};
