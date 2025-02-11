class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0], maxEnding = nums[0];
        for (int i = 1, length = nums.size(); i < length; i++) {
            maxEnding = max(maxEnding + nums[i], nums[i]);
            result = max(result, maxEnding);
        }
        return result;
    }
};