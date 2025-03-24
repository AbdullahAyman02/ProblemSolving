class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int result = 0, last = 0;

        sort(meetings.begin(), meetings.end());

        for (auto & meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            if (start > last + 1) {
                result += start - last - 1;
            }

            last = max(last, end);
        }

        result += days - last;

        return result;
    }
};