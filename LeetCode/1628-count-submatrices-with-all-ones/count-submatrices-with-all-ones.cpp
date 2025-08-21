class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int result = 0;
        vector<vector<int>> row(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) row[i][j] = mat[i][j];
                else row[i][j] = (mat[i][j] == 0) ? 0 : row[i][j - 1] + 1;

                int current = row[i][j];
                for (int k = i; k >= 0; k--) {
                    current = min(current, row[k][j]);
                    if (current == 0) break;
                    result += current;
                }
            }
        }

        return result;
    }
};