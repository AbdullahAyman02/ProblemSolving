class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc_length = 1, dec_length = 1, max_length = 1;
        if (nums.size() == 1)
            return 1;
        for (int i = 0, length = nums.size(); i < length - 1; i++) {
            if (nums[i + 1] > nums[i]) {
                inc_length++;
                dec_length = 1;
            }
            else if (nums[i + 1] < nums[i]) {
                inc_length = 1;
                dec_length++;
            }
            else {
                inc_length = 1;
                dec_length = 1;
            }
            max_length = max(max_length, max(inc_length, dec_length));
        }
        return max_length;
    }
};