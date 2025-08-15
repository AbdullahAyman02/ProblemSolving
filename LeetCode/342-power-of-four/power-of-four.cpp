class Solution {
public:
    bool isPowerOfFour(int n) {
        double result = log(n) / log(4);
        double epsilon = 1e-10;
        return ceil(result) - result <= epsilon;
    }
};