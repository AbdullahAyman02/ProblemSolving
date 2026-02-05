class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int length = nums.size();
        vector<int> result(length);
        for (int i = 0; i < length; i++) {
            int targetidx = ((i + nums[i]) % length + length) % length;
            result[i] = nums[targetidx];
        }

        return result;
    }
};