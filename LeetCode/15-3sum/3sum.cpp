class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> triplets;
        vector<vector<int>> result;
        long long sum = 0;
        for (int i = 0, length = nums.size(), j, k; i < length; i++) {
            j = i + 1, k = length - 1;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    triplets.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    continue;
                }
                else if (sum > 0)
                    k--;
                else
                    j++;
            }
        }
        for (auto triplet : triplets)
            result.emplace_back(triplet);
        return result;
    }
};