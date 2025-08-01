class Solution {
public:
    char kthCharacter(int k) {
        int result = 0, t;
        while (k != 1) {
            t = __lg(k);
            if ((1 << t) == k) --t;
            k = k - (1 << t);
            result++;
        }
        return 'a' + result;
    }
};