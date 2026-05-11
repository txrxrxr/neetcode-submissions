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
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() < 2) {
            return intervals.size();
        }
        std::map<int, int> m;
        for (const auto& i : intervals) {
            ++m[i.start];
            --m[i.end];
        }

        int cnt = 0;
        int ans = 0;
        for (const auto& [_, e] : m) {
            cnt += e; 
            ans = std::max(ans, cnt);
        }
        return ans;
    }
};
