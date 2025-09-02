class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int result = 0;

        for (int i = 0, length = points.size(); i < length; i++) {
            auto& pointA = points[i];
            for (int j = 0; j < length; j++) {
                vector<int> pointB = points[j];
                if (i == j || !(pointA[0] <= pointB[0] && pointA[1] >= pointB[1])) continue;

                if (length == 2) {
                    result++; 
                    continue;
                }

                bool illegal = false;
                for (int k = 0; k < length; k++) {
                    if (k == i || k == j) continue;

                    auto& tempPoint = points[k];
                    bool isXContained = tempPoint[0] >= pointA[0] && tempPoint[0] <= pointB[0];
                    bool isYContained = tempPoint[1] <= pointA[1] && tempPoint[1] >= pointB[1];
                    if (isXContained && isYContained) {
                        illegal = true;
                        continue;
                    }
                }

                if (!illegal) result++;
            }
        }

        return result;
    }
};