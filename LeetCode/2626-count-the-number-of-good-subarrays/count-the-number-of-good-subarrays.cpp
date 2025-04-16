class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int length = nums.size();
        int same = 0, right = -1;
        unordered_map<int, int> count;
        long long result = 0;
        for (int left = 0; left < length; left++) {
            while (same < k && right + 1 < length) {
                right++;
                same += count[nums[right]];
                count[nums[right]]++;
            }

            if (same >= k)
                result += length - right;

            count[nums[left]]--;
            same -= count[nums[left]];
        }

        return result;
    }
};