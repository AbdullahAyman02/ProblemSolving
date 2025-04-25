class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int length = nums.size();
        unordered_map<int, int> count;
        long long result = 0;
        int prefix = 0;
        count[0] = 1;
        for (int i = 0; i < length; i++) {
            prefix += nums[i] % modulo == k;
            result += count[(prefix - k + modulo) % modulo];
            count[prefix % modulo]++;
        }

        return result;
    }
};