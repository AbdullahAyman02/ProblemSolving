class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (!(k % 2) || !(k % 5)) return -1;
        long long num = 1; int result = 1;
        while (num % k) {
            num = (num * 10 + 1) % k;
            result++;
            if (result > k) return -1;
        }
        return result;
    }
};