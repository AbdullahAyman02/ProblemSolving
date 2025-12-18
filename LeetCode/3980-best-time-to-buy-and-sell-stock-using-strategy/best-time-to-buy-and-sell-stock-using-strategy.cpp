class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int length = prices.size();
        long long initialProfit = 0;

        for (int i = 0; i < length; i++) {
            initialProfit += 1LL * prices[i] * strategy[i];
        }

        vector<long long> prefixProfit(length + 1, 0);
        vector<long long> prefixPrice(length + 1, 0);

        for (int i = 0; i < length; i++) {
            prefixProfit[i + 1] = prefixProfit[i] + 1LL * prices[i] * strategy[i];
            prefixPrice[i + 1] = prefixPrice[i] + prices[i];
        }

        long long maxGain = 0;
        for (int i = 0; i + k <= length; i++) {
            long long oldGain = prefixProfit[i + k] - prefixProfit[i];
            long long newGain = prefixPrice[i + k] - prefixPrice[i + k / 2];
            maxGain = max(maxGain, newGain - oldGain);
        }

        return initialProfit + maxGain;
    }
};