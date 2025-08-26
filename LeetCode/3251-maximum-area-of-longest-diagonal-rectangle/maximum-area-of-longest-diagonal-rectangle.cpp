class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int result = 0;
        double diagonal = 0;
        for (int i = 0, length = dimensions.size(); i < length; i++) {
            double temp = sqrt(dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1]);
            if (temp > diagonal) diagonal = temp, result = dimensions[i][0] * dimensions[i][1];
            else if (temp == diagonal) result = max(result, dimensions[i][0] * dimensions[i][1]);
        }
        return result;
    }
};