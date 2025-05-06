class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int i = 0;
        for (auto num : nums)
            result[i++] = nums[num];
        return result;
    }
};