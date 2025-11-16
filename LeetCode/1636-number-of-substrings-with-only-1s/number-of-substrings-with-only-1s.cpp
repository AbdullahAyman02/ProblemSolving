class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        int p = 0;
        long long result = 0;
        while (p < s.size()) {
            if (s[p] == '0') {
                p++;
                continue;
            }
            int count = 0;
            while(p < s.size() && s[p] == '1') {
                count++;
                p++;
            }
            result = result + (1LL + (long long)count) * count / 2;
            result = result % MOD;
        }
        return result;
    }
};