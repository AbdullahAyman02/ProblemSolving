class Solution {
public:
    long long dp[1001][501][3];

    long long solve(int idx, int state, int k, int n, vector<int>& prices) {
        if ((k == 0 || idx == n) && state == 0) return 0;
        if ((k == 0 || idx == n) && state != 0) return -(1e18);

        if (dp[idx][k][state] != -1) return dp[idx][k][state];

        if (state == 0) { // no position -> we can either continue, buy new or sell now
            long long temp1 = solve(idx + 1, 0, k, n, prices);      // Proceeding without any action
            long long temp2 = -prices[idx] + solve(idx + 1, 1, k, n, prices);   // Buying a stock
            long long temp3 = prices[idx] + solve(idx + 1, 2, k, n, prices);    // Selling a stock

            return dp[idx][k][state] = max({temp1, temp2, temp3});
        } else if (state == 1) {    // If a stock has already been bought -> actions are to either proceed without any action, or to sell the stock
            long long temp1 = solve(idx + 1, 1, k, n, prices);  // Proceeding without any action
            long long temp2 = prices[idx] + solve(idx + 1, 0, k - 1, n, prices);    // Stock has been sold

            return dp[idx][k][state] = max(temp1, temp2);
        } else {    // If a stock has already been sold -> actions are to either proceed without any action, or to buy back the stock
            long long temp1 = solve(idx + 1, 2, k, n, prices);  // Proceeding without any action
            long long temp2 = -prices[idx] + solve(idx + 1, 0, k - 1, n, prices);   // Stock has been bought back

            return dp[idx][k][state] = max(temp1, temp2);
        }

        return 0;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp, -1, sizeof(dp));
        int n = prices.size();
        return solve(0, 0, k, n, prices);
    }
};