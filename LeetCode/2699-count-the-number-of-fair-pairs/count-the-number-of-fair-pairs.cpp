class Solution {
    long long lower_bound(vector<int>& nums, int low, int high, int element) {
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (nums[mid] >= element) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long result = 0;

        for (int i = 0, length = nums.size(); i < length; i++) {
            int low = lower_bound(nums, i + 1, length - 1, lower - nums[i]);

            int high = lower_bound(nums, i + 1, length - 1, upper - nums[i] + 1);

            result += 1LL * (high - low);
        }

        return result;
    }
};