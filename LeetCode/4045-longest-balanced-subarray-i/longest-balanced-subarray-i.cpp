class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int result = 0;

        for (int i = 0, length = nums.size(); i < length; i++) {
            unordered_set<int> even, odd;

            for (int j = i; j < length; j++) {
                if (nums[j] % 2 == 0) even.insert(nums[j]);
                else odd.insert(nums[j]);

                if (even.size() == odd.size()) result = max(result, j - i + 1);
            }
        }

        return result;
    }
};