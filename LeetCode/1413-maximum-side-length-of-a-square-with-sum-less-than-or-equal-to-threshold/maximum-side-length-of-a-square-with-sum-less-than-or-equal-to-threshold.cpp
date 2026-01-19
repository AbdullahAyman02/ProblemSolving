class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = mat[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
            }
        }

        int maxSide = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int nextSide = maxSide + 1;

                if (i >= nextSide && j >= nextSide) {
                    int sum = prefixSum[i][j] - prefixSum[i - nextSide][j] - prefixSum[i][j - nextSide] + prefixSum[i - nextSide][j - nextSide];

                    if (sum <= threshold) {
                        maxSide = nextSide;
                    }
                }
            }
        }

        return maxSide;
    }
};