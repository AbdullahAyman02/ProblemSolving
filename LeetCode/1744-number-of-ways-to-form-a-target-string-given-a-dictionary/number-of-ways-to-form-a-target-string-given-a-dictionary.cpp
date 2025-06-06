class Solution {
public:
    const int MOD = 1e9 + 7;
    int numWays(vector<string>& words, string target) {
        int k = words[0].size();
        int m = target.length();
        vector<vector<long long>> freq(26, vector<long long>(k));
        for (int col = 0; col < k; col++) {
            for (string& word : words) {
                freq[word[col] - 'a'][col]++;
            }
        }
        vector<vector<long long>> dp(m + 1, vector<long long>(k + 1));
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= k; j++) {
                if (j < k) {
                    dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
                }
                if (i < m && j < k) {
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + freq[target[i] - 'a'][j] * dp[i][j]) % MOD;
                }
            }
        }
        return dp[m][k];
    }
};