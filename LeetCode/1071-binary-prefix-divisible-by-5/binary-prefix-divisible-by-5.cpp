class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result(nums.size(), false);
        int number = nums[0]; result[0] = !number;
        for (int i = 1, length = nums.size(); i < length; i++) {
            number = ((number << 1) + nums[i]) % 5;
            result[i] = !(number % 5);
        }
        return result;
    }
};