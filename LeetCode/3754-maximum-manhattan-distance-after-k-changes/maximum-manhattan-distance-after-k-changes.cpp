class Solution {
public:
    int maxDistance(string s, int k) {
        int x = 0, y = 0, result = 0;
        for (int i = 0, length = s.size(); i < length; i++) {
            switch (s[i]) {
                case 'N':
                    y++; break;
                case 'S':
                    y--; break;
                case 'E':
                    x++; break;
                case 'W':
                    x--; break;
            }
            result = max(result, min(abs(x) + abs(y) + k * 2, i + 1));
        }
        return result;
    }
};