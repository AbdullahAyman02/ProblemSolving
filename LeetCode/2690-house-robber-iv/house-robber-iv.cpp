class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int minReward = 1, maxReward = *max_element(nums.begin(), nums.end()), totalHouses = nums.size();

        while(minReward < maxReward) {
            int midReward = (minReward + maxReward) / 2;
            int possibleThefts = 0;

            for (int i = 0; i < totalHouses; i++) {
                if (nums[i] <= midReward) {
                    possibleThefts += 1;
                    i++;
                }
            }

            if (possibleThefts >= k)
                maxReward = midReward;
            else
                minReward = midReward + 1;
        }

        return minReward;
    }
};