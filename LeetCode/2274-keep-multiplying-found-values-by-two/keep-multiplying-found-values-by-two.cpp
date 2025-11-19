class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        int i = 0, length = nums.size();
        while(i < length && nums[i] != original) i++;
        if (i == length) return original;
        while(i < length) {
            if (nums[i] == original)
                original *= 2;
            i++;
        }
        return original;
    }
};