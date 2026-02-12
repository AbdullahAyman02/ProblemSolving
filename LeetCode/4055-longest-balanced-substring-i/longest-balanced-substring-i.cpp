class Solution {
public:
    bool issamefreq(const vector<int>& arr) {
        int temp = -1;
        for (auto a : arr) {
            if (a != 0) {
                if (temp == -1) temp = a;
                else if (temp != a) return false;
            }
        }
        return true;
    }

    int longestBalanced(string s) {
        int result = 0;
        int length = s.size();

        for (int i = 0; i < length; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < length; j++) {
                freq[s[j] - 'a']++;

                if (issamefreq(freq)) result = max(result, j - i + 1);
            }
        }

        return result;
    }
};