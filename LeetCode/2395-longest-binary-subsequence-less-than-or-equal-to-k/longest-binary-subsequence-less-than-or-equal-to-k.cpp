class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sum = 0, count = 0;
        int bits = 32 - __builtin_clz(k);
        for (int i = 0, length = s.size(); i < length; i++) {
            char c = s[length - 1 - i];
            if (c == '1') {
                if (i < bits && sum + (1 << i) <= k) {
                    sum += 1 << i;
                    count++;
                }
            } else count++;
        }
        return count;
    }
};