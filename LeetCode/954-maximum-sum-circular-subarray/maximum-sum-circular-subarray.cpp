class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxEnding = nums[0], minEnding = nums[0], total = nums[0];
        int maximum = nums[0], minimum = nums[0];
        for (int i = 1, length = nums.size(); i < length; i++) {
            maxEnding = max(maxEnding + nums[i], nums[i]);
            minEnding = min(minEnding + nums[i], nums[i]);
            maximum = max(maximum, maxEnding);
            minimum = min(minEnding, minimum);
            total += nums[i];
        }
        if (minimum == total)
            return maximum;
        return max(maximum, total - minimum);
    }
};