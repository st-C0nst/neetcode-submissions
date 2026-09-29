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
        if (intervals.size() == 0) return true;
        sort(intervals.begin(), intervals.end(), [](const Interval a, const Interval b) {return a.start < b.start;});

        Interval prevInt = intervals[0];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < prevInt.end) {
                return false;
            }
            prevInt = intervals[i];
        }

        return true;
    }
};
