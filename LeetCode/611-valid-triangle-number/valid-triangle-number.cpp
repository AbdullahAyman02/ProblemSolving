class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0, length = nums.size(); i < length; i++) {
            int k = i + 2;
            for (int j = i + 1; j < length - 1 && nums[i] != 0; j++) {
                while (k < length && nums[i] + nums[j] > nums[k]) k++;
                result += k - j - 1;
            }
        }

        return result;
    }
};