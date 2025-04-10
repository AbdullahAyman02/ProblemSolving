class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;    // key = number, value = index
        int index1 = -1, index2 = -1;
        for (int i = 0, length = nums.size(); i < length; i++) {
            long long rem = target - nums[i];
            auto it = map.find(rem);
            if (it != map.end()) {
                index1 = i;
                index2 = it->second;
            }
            map[nums[i]] = i;
        }
        return {index1, index2};
    }
};