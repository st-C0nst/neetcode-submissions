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
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](const Interval a, const Interval b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> window;
        window.push(intervals[0].end);

        for (int i = 1; i < intervals.size(); ++i) {
            int currSmallest = window.top();
            window.push(intervals[i].end);

            if (intervals[i].start >= currSmallest) {
                window.pop();
            }
        }

        return window.size();
    }
};
