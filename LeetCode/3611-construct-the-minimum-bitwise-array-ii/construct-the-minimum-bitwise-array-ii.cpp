class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int length = nums.size();
        vector<int> result(length);

        for (int i = 0; i < length; i++) {
            int x = nums[i];
            if ((x & 1) == 0) result[i] = -1;
            else {
                int bit = 0;
                while (((x >> bit) & 1) == 1) bit++;

                result[i] = x - (1 << (bit - 1));
            }
        }

        return result;
    }
};