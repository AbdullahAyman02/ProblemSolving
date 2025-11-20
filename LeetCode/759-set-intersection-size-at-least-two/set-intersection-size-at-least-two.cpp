class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        stable_sort(intervals.begin(), intervals.end(), [](const auto& x, const auto& y) {return x[0] > y[0];});
        stable_sort(intervals.begin(), intervals.end(), [](const auto& x, const auto& y) {return x[1] < y[1];});

        vector<int> pre;
        int result = 0;
        vector<int> previousInterval;
        for (const auto& interval : intervals) {
            if (!previousInterval.empty() && previousInterval[1] == interval[1]) {
                previousInterval = interval;
                continue;
            }
            previousInterval = interval;
            int start = interval[0];
            int end = interval[1];
            if (pre.empty() || pre[1] < start) {
                result += 2;
                pre = vector<int> {end - 1, end};
            } else if (pre[0] < start) {
                result += 1;
                pre = vector<int> {pre[1], end};
            }
        }

        return result;
    }
};