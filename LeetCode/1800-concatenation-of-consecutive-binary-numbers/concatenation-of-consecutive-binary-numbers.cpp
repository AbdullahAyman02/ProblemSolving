class Solution {
public:
    int concatenatedBinary(int n) {
        int MOD = 1e9 + 7;
        long long result = 0;

        for (int i = 1; i <= n; i++) {
            int shift = 0;
            int num = i;
            while(num) {
                num >>= 1;
                shift++;
            }

            result = ((result << shift) % MOD + i) % MOD;
        }

        return (int)result;
    }
};