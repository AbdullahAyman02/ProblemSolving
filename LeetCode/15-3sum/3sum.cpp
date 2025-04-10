class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        long long sum = 0;
        for (int i = 0, length = nums.size(), j, k; i < length - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            j = i + 1, k = length - 1;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while(j + 1 < k && nums[j] == nums[j + 1]) j++;
                    while(j < k - 1 && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                }
                else if (sum > 0)
                    k--;
                else
                    j++;
            }
        }
        return result;
    }
};