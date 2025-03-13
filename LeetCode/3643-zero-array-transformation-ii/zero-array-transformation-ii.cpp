class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int length = nums.size(), sum = 0, k = 0;
        vector<int> differenceArray(length + 1);

        for (int i = 0; i < length; i++) {
            while (sum + differenceArray[i] < nums[i]) {
                k++;

                if (k > queries.size())
                    return -1;

                int left = queries[k - 1][0], right = queries[k - 1][1], val = queries[k - 1][2];
                if (right >= i) {
                    differenceArray[max(left, i)] += val;
                    differenceArray[right + 1] -= val;
                }
            }
            sum += differenceArray[i];
        }
        return k;
    }
};