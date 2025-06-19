class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 1;
        int rec = nums[0];
        for (int i = 0, length = nums.size(); i < length; i++) {
            if (nums[i] - rec > k) {
                result++;
                rec = nums[i];
            }
        }

        return result;
    }
};