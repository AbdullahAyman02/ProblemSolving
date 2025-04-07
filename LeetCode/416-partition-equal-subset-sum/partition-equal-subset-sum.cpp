class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = 0;
        for (auto num : nums) sum += num;
        if (sum % 2 != 0) return false;

        bitset<10001> bit(1);
        for (auto num : nums) {
            bit |= bit << num;

            if (bit[sum / 2])
                return true;
        }

        return bit[sum / 2];
    }
};