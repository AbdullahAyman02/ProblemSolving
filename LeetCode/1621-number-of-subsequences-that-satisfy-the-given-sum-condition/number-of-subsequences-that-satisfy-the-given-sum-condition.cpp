class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7, length = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> power(length, 1);
        for (int i = 1; i < length; i++)
            power[i] = (power[i - 1] * 2) % MOD;

        int left = 0, right = length - 1, result = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + power[right - left]) % MOD;
                left++;
            } else --right;
        }

        return result;
    }
};