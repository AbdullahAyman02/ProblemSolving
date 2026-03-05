class Solution {
public:
    int solve(string& s, char ch) {
        int result = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (!(i & 1) && s[i] != ch) result++;
            else if ((i & 1) && s[i] == ch) result++;
        }

        return result;
    }

    int minOperations(string s) {
        int opt1 = solve(s, '0');
        int opt2 = solve(s, '1');

        return min(opt1, opt2);
    }
};