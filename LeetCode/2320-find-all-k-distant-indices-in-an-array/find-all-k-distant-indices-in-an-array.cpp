class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int r = 0;
        for (int j = 0, length = nums.size(); j < length;  j++) {
            if (nums[j] == key) {
                int l = max(r, j - k);
                r = min(length - 1, j + k) + 1;
                for (int i = l; i < r; i++)
                    result.push_back(i);
            }
        }
        return result;
    }
};