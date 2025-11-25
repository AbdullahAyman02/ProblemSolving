class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (!(k % 2) || !(k % 5)) return -1;
        int rem = 1; int result = 1;
        while (rem % k) {
            rem = (rem * 10 + 1) % k;
            result++;
            if (result > k) return -1;
        }
        return result;
    }
};