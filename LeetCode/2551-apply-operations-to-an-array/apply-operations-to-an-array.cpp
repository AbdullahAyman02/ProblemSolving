class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int length = nums.size();
        int zeroIndex = 0;

        for (int i = 0; i < length; i++) {
            if (i < length - 1 && nums[i] == nums[i + 1] && nums[i] != 0) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }

            if (nums[i] != 0) {
                if (i != zeroIndex) 
                    swap(nums[i], nums[zeroIndex]);
                zeroIndex++;
            }
        }

        return nums;
    }
};