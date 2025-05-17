class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> colors;
        for (auto num : nums)
            colors[num]++;
        for (int i = 0, length = nums.size(); i < length; i++) {
            nums[i] = i < colors[0] ? 0 : i < colors[0] + colors[1] ? 1 : 2;
        }
    }
};