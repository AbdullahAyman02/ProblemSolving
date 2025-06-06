class Solution {
public:
    int solve(vector<int>& days, int n, vector<int>& costs,vector<int>&dp) 
    {
        if (n >= 366) {
            return 0;
        }

        if(dp[n]!=-1)
            return dp[n];
        
        if (days[n] == 1) 
        {
            return dp[n]=min(costs[0] + solve(days, n + 1, costs, dp), min(costs[1] + solve(days, n + 7, costs, dp), costs[2] + solve(days, n + 30, costs, dp)));
        } 
        else 
        {
            return dp[n]=solve(days, n + 1, costs, dp);
        }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> d(366, 0);
        
        for (int i = 0; i < days.size(); i++) {
            d[days[i]] = 1;
        }
        
        vector<int> dp(366,-1);
        
        return solve(d, 1, costs, dp);
    }
};