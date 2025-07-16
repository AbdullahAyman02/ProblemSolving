class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int result = 0;
        vector<vector<int>> patterns = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        for (auto& pattern : patterns) {
            int count = 0;
            for (int num : nums) if (num % 2 == pattern[count % 2]) count++;
            result = max(result, count);
        }
        return result;
    }
};