class Solution {
public:
    bool isPowerOfThree(int n) {
        double result = log(n) / log(3);
        double eps = 1e-10;
        return ceil(result) - result < eps;
    }
};