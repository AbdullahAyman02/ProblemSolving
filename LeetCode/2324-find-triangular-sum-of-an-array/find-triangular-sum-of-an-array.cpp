class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> new_nums;
            for (int i = 0, length = nums.size() - 1; i < length; i++)
                new_nums.emplace_back((nums[i] + nums[i + 1]) % 10);
            nums = move(new_nums);
        }
        return nums[0];
    }
};