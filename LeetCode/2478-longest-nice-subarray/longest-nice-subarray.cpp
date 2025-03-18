class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int usedBits = 0;
        int start = 0;
        int maxLength = 0;

        for (int i = 0, length = nums.size(); i < length; i++) {
            while ((usedBits & nums[i]) != 0) {
                usedBits ^= nums[start];
                start++;
            }

            usedBits |= nums[i];

            maxLength = max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};