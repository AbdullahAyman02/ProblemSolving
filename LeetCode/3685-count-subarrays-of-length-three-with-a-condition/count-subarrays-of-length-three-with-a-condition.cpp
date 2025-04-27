class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int result = 0;
        for (int i = 1, length = nums.size(); i < length - 1; i++)
            if (nums[i] == (nums[i - 1] + nums[i + 1]) * 2)
                result++;
        return result;
    }
};