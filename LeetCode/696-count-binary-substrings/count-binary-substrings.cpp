class Solution {
public:
    int countBinarySubstrings(string s) {
        int strk = 1, result = 0, prev = 0;;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) strk++;
            else {
                prev = strk;
                strk = 1;
            }

            if (strk <= prev) result++;
        }

        return result;
    }
};