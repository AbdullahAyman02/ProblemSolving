class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int prev;
        int result = 0;
        for (int i = 0; i < strs[0].size(); i++) {
            prev = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] < prev) {
                    result++;
                    break;
                }
                prev = strs[j][i];
            }
        }
        return result;
    }
};