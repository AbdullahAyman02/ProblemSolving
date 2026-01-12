class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int result = 0;
        for (int i = 1, length = points.size(); i < length; i++) {
            int x = abs(points[i][0] - points[i - 1][0]);
            int y = abs(points[i][1] - points[i - 1][1]);
            result += min(x, y) + abs(x - y);
        }

        return result;
    }
};