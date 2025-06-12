class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int result = abs(nums[nums.size() - 1] - nums[0]);
        for (int i = 1, length = nums.size(); i < length; i++)
            result = max(result, abs(nums[i] - nums[i - 1]));
        return result;
    }
};