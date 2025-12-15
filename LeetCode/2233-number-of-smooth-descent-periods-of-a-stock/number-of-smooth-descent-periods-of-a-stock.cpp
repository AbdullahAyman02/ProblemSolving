class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int length = prices.size();

        long long result = 0;

        for (int i = 0, j = 0; i < length; i++) {
            j = i + 1;
            while (j < length && prices[j] == prices[j - 1] - 1) j++;
            long long c = j - i;
            result += c * (c + 1) / 2;
            i = j - 1;
        }

        return result;
    }
};