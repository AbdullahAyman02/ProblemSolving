class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int length = weights.size();

        vector<int> pairWeights(length - 1, 0);

        for (int i = 0; i < length - 1; i++)
            pairWeights[i] += weights[i] + weights[i + 1];

        sort(pairWeights.begin(), pairWeights.end());

        long long answer = 0;
        for (int i = 0; i < k - 1; i++)
            answer += pairWeights[length - 2 - i] - pairWeights[i];

        return answer;
    }
};