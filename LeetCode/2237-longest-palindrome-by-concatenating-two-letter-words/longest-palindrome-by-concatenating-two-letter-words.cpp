class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> map;
        for (auto word : words) map[word]++;

        int result = 0, prevPalindrome = 0;
        for (auto& [word, frequency] : map) {
            string s = word;
            reverse(s.begin(), s.end());
            if (word == s) {
                result += (frequency / 2) * 4;
                if (frequency % 2) prevPalindrome = 1;
            } else if (word < s && map.count(s))
                result += min(frequency, map[s]) * 4;
        }

        return result + prevPalindrome * 2;
    }
};