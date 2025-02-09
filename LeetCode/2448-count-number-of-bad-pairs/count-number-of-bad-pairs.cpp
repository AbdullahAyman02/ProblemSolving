class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long badPairs = 0;
        unordered_map<int, int> diffCount;

        for (int i = 0, length = nums.size(); i < length; i++) {
            int diff = i - nums[i];
            int goodPairsCount = diffCount[diff];
            badPairs += i - goodPairsCount;
            diffCount[diff] = goodPairsCount + 1;
        }

        return badPairs;
    }
};