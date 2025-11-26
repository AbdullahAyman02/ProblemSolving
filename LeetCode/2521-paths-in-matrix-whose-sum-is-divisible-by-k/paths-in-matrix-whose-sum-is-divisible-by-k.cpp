class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1000000007;
        int rowCount = grid.size(), colCount = grid[0].size();
        
        vector<vector<int>> dp(colCount, vector<int>(k, 0));
        vector<vector<int>> nextDp(colCount, vector<int>(k, 0));

        int prefixMod = 0;

        for (int col = 0; col < colCount; ++col) {
            prefixMod = (prefixMod + grid[0][col]) % k;
            dp[col][prefixMod]++;
        }

        prefixMod = grid[0][0] % k;

        for (int row = 1; row < rowCount; row++) {
            fill(nextDp[0].begin(), nextDp[0].end(), 0);

            prefixMod = (prefixMod + grid[row][0]) % k;
            nextDp[0][prefixMod]++;

            for (int col = 1; col < colCount; col++) {
                for (int remainder = 0; remainder < k; remainder++) {
                    int nextRemainder = (remainder + grid[row][col]) % k;

                    nextDp[col][nextRemainder] = (dp[col][remainder] + nextDp[col - 1][remainder]) % MOD;
                }
            }

            swap(dp, nextDp);

        }

        return dp[colCount - 1][0];
    }
};