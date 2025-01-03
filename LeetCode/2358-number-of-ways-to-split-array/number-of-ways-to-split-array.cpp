class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long first = 0, last = 0;
        for (int num : nums) {
            last += num;
        }
        int result = 0;
        for (int i = 0, length = nums.size(); i < length - 1; i++) {
            first += nums[i];
            last -= nums[i];
            if (first >= last) {
                result++;
            }
        }
        return result;
    }
};