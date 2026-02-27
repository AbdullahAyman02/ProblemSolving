class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int zero = 0;

        for (char c : s) if (c == '0') zero++;

        if (zero == 0) return 0;

        if (n == k) {
            if (zero == n) return 1;
            return -1;
        }

        int one = n - zero;
        int base = n - k;

        int result = INT_MAX;

        if ((k % 2) == (zero % 2)) {
            long long m = max((zero + k - 1) / k, (one + base - 1) / base);

            if (m % 2 == 0) m++;

            result = min(result, (int)m);
        }

        if (zero % 2 == 0) {
            long long m = max((zero + k - 1) / k, (zero + base - 1) / base);

            if (m % 2 == 1) m++;

            result = min(result, (int)m);
        }

        return result == INT_MAX ? -1 : result;
    }
};