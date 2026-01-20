class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int length = nums.size();
        vector<int> result(length);
        for (int i = 0; i < length; i++) {
            int num = nums[i];
            int x = -1;
            int d = 1;

            while ((num & d) != 0) {
                x = num - d;
                d <<= 1;
            }

            result[i] = x;
        }

        return result;
    }
};