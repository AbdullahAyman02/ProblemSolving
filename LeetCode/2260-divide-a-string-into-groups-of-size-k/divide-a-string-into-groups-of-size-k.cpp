class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int length = s.size();
        vector<string> result;
        int current = 0;
        while (current < length) {
            result.push_back(s.substr(current, k));
            current += k;
        }
        result.back() += string(k - result.back().length(), fill);
        return result;
    }
};