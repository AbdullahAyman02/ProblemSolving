class Solution {
public:
    int countTriples(int n) {
        int result = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = a + 1; b <= n; b++) {
                float c = sqrt(a * a + b * b);
                if (c > n) break;
                if (c == floor(c)) result += 2;
            }
        }

        return result;
    }
};