class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int length = nums.size();
        long long res = 0, imax = 0, dmax = 0;
        for (int k = 0; k < length; k++) {
            res = max(res, dmax * nums[k]);
            dmax = max(dmax, imax - nums[k]);
            imax = max(imax, static_cast<long long>(nums[k]));
        }

        return res;
    }
};