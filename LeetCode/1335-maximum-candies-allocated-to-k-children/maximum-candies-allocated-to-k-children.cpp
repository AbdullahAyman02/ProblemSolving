class Solution {
    bool canAllocateCandies(vector<int>& candies, long long k, int middle) {
        long long maxNumOfChildren = 0;
        for (int i = 0, length = candies.size(); i < length; i++) {
            maxNumOfChildren += candies[i] / middle;
        }
        return maxNumOfChildren >= k;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int maxInPile = *max_element(candies.begin(), candies.end());
        
        int left = 0, right = maxInPile;

        while (left < right) {
            int middle = (left + right + 1) / 2;
            if (canAllocateCandies(candies, k, middle))
                left = middle;
            else
                right = middle - 1;
        }

        return left;
    }
};