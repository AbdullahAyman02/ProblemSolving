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
    int minMaxDifference(int num) {
        int k = 0;
        int m = 9;
        int rem = num;
        while (rem > 0) {
            int const digit = rem % 10;
            k = digit;
            if (digit != 9) m = digit;
            rem /= 10;
        }
        return remapDigit(num, m, 9) - remapDigit(num, k, 0);
    }
};