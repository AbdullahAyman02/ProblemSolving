class Solution {
    int remapDigit(int x, int from, int to) {
        if (from == to) return x;
        int answer = x, rem = x, p = 1;
        while (rem > 0) {
            if (rem % 10 == from) answer += (to - from) * p;
            p *= 10;
            rem /= 10;
        }
        return answer;
    }
public:
    int maxDiff(int num) {
        int k = 1, d = 1, m = 9;
        int rem = num;
        while (rem > 0) {
            int const digit = rem % 10;
            if (digit > 1) k = digit;
            if (digit != 9) m = digit;
            d = k == digit;
            rem /= 10;
        }
        return remapDigit(num, m, 9) - remapDigit(num, k, d);
    }
};