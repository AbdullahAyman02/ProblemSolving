class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), sum1 = 0, sum2 = 0, sum3 = 0;
        int max1 = 0, max2 = 0, max3 = 0;
        int index1 = 0, index2 = 0, index3 = k;
        vector<int> ans = {0, k, 2 * k};

        for (int i = 0; i < k; i++) {
            sum1 += nums[i];
            sum2 += nums[i + k];
            sum3 += nums[i + 2 * k];
        }
        max1 = sum1;
        max2 = sum1 + sum2;
        max3 = sum1 + sum2 + sum3;

        for (int i = 0; i <= n - 3 * k; i++) {
            if (i > 0) {
                sum1 = sum1 - nums[i - 1] + nums[i + k - 1];
                sum2 = sum2 - nums[i + k - 1] + nums[i + 2 * k - 1];
                sum3 = sum3 - nums[i + 2 * k - 1] + nums[i + 3 * k - 1];
            }

            if (sum1 > max1) {
                max1 = sum1;
                index1 = i;
            }

            if (max1 + sum2 > max2) {
                max2 = max1 + sum2;
                index2 = index1;
                index3 = i + k;
            }

            if (max2 + sum3 > max3) {
                max3 = max2 + sum3;
                ans = {index2, index3, i + 2 * k};
            }
        }

        return ans;
    }
};