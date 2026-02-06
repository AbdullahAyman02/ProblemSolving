class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int j = 0, length = nums.size(); j < length; j++) {
            if (result <= j && (long long)nums[j] > (long long)nums[result] * k) result++;
        }

        return result;
    }
};