class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int result = -1, prefixMin = nums[0];
        for (int i = 1, length = nums.size(); i < length; i++)
            if (nums[i] > prefixMin)
                result = max(result, nums[i] - prefixMin);
            else
                prefixMin = min(prefixMin, nums[i]);
        return result;
    }
};