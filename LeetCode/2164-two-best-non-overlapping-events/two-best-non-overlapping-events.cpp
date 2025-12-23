class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        vector<vector<int>> endSorted = events;
        sort(endSorted.begin(), endSorted.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<int> maxValueTill(n);

        maxValueTill[0] = endSorted[0][2];
        for (int i = 1; i < n; i++)
            maxValueTill[i] = max(maxValueTill[i - 1], endSorted[i][2]);

        int result = 0, j = 0;

        for (int i = 0; i < n; i++) {
            int start = events[i][0];
            int value = events[i][2];

            while (j < n && endSorted[j][1] < start) j++;

            result = max(result, value);

            if (j > 0) result = max(result, value + maxValueTill[j - 1]);
        }

        return result;
    }
};