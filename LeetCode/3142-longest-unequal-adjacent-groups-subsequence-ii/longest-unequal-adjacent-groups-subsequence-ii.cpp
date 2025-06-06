class Solution {
    bool check(string &s1, string &s2) {
        if (s1.size() != s2.size()) return false;
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            diff += s1[i] != s2[i];
            if (diff > 1)
                return false;
        }
        return diff == 1;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int length = groups.size();
        vector<int> dp(length, 1);
        vector<int> prev(length, -1);
        int maxIndex = 0;
        for (int i = 1; i < length; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[i], words[j]) == 1 && dp[j] + 1 > dp[i] && groups[i] != groups[j]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }

            if (dp[i] > dp[maxIndex]) maxIndex = i;
        }

        vector<string> result;
        for (int i = maxIndex; i >= 0; i = prev[i])
            result.emplace_back(words[i]);

        reverse(result.begin(), result.end());
        return result;
    }
};