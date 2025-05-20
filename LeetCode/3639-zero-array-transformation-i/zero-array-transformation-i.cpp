class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> differenceArray(nums.size() + 1, 0);
        for (auto& query : queries) {
            int left = query[0], right = query[1];
            differenceArray[left]++;
            differenceArray[right + 1]--;
        }

        vector<int> operationCounts;
        int curr = 0;
        for (int diff : differenceArray) {
            curr += diff;
            operationCounts.push_back(curr);
        }

        for (int i = 0, length = nums.size(); i < length; i++)
            if (operationCounts[i] < nums[i])
                return false;
        return true;
    }
};