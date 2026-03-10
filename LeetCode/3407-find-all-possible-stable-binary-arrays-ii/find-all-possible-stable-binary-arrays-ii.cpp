class Solution {
public:
    const int N = 1e9 + 7;
    int dp[1001][1001][2];
    
    int f1(int i, int j, int l) {
        if (i < 0 || j < 0) return 0;
        if (i == 0 && j == 0) return 1;
        if (dp[i][j][1] != -1) return dp[i][j][1];

        int result = 0;
        for(int k = 1; k <= l; k++) {
            result = ((long long)result + f0(i, j - k, l)) % N;
        }

        return dp[i][j][1] = result;
    }

    int f0(int i, int j, int l) {
        if (i < 0 || j < 0) return 0;
        if (i == 0 && j == 0) return 1;
        if (dp[i][j][0] != -1) return dp[i][j][0];

        int result = 0;
        for (int k = 1; k <= l; k++) {
            result = ((long long)result + f1(i - k, j, l)) % N;
        }

        return dp[i][j][0] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        for(int i=0;i<=min(limit,max(one,zero));i++){
            dp[i][0][0]=dp[0][i][1]=1;
        }
        for(int i=1;i<=zero;i++){
            for(int j=1;j<=one;j++){
                dp[i][j][0]=((long long)dp[i-1][j][0]+dp[i-1][j][1])%N;
                dp[i][j][1]=((long long)dp[i][j-1][1]+dp[i][j-1][0])%N;
                
                if(i-1-limit>=0) dp[i][j][0]=dp[i][j][0]-dp[i-1-limit][j][1];
                if(j-1-limit>=0) dp[i][j][1]=dp[i][j][1]-dp[i][j-1-limit][0];
                if(dp[i][j][0]<0) dp[i][j][0]+=N;
                if(dp[i][j][1]<0) dp[i][j][1]+=N;
            }
        }
        return ((long long)dp[zero][one][1]+dp[zero][one][0])%N;
    }
};