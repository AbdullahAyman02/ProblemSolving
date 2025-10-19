class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int length = s.size();
        string result = s;
        s = s + s;
        int g = gcd(b, length);

        auto add = [&](string& t, int start) {
            int minVal = 10, times = 0;
            for (int i = 0; i < 10; i++) {
                int added = ((t[start] - '0') + i * a) % 10;
                if (added < minVal) {
                    minVal = added;
                    times = i;
                }
            }
            for (int i = start; i < length; i += 2) {
                t[i] = '0' + ((t[i] - '0') + times * a) % 10;
            }
        };

        for (int i = 0; i < length; i += g) {
            string t = s.substr(i, length);
            add(t, 1);
            if (b % 2) {
                add(t, 0);
            }
            result = min(result, t);
        }

        return result;
    }
};