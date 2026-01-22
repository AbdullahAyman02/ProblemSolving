class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int length = nums.size();
        int count = 0;

        while (length > 1) {
            int minSum = INT_MAX;
            int minIdx = -1;
            bool isSorted = true;

            for (int i = 1; i < length; i++) {
                if (nums[i - 1] + nums[i] < minSum) {
                    minSum = nums[i - 1] + nums[i];
                    minIdx = i - 1;
                }
                if (nums[i - 1] > nums[i]) isSorted = false;
            }

            if (isSorted) return count;

            nums[minIdx] = minSum;

            for (int i = minIdx + 1; i < length - 1; i++) nums[i] = nums[i + 1];

            count++;
            length--;
        }

        return count;
    }
};