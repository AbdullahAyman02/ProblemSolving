class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> subArrays;
        int currLength = 0;
        for (auto num : nums) {
            if (num == 0) {
                if (currLength) subArrays.emplace_back(currLength), currLength = 0;
                else subArrays.emplace_back(0);
            }
            else currLength++;
        }
        if (currLength) subArrays.emplace_back(currLength);
        // if (subArrays.empty()) return 0;
        int result = subArrays[0] == 0 ? 0 : subArrays[0] - 1;
        for (int i = 1, length = subArrays.size(); i < length; i++)
            result = max(subArrays[i] + subArrays[i - 1], result);
        return result;
    }
};