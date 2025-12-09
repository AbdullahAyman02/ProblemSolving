class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> numCnt;
        unordered_map<int, int> numPartialCnt;

        numCnt.reserve(nums.size() * 2);
        numPartialCnt.reserve(nums.size() * 2);

        for (int num : nums) numCnt[num]++;

        int result = 0;
        for (int num : nums) {
            int target = num * 2;
            int leftCnt = numPartialCnt[target];
            numPartialCnt[num]++;
            int rightCnt = numCnt[target] - numPartialCnt[target];
            result = (result + (leftCnt * 1LL * rightCnt % MOD)) % MOD;
        }

        return result;
    }
};