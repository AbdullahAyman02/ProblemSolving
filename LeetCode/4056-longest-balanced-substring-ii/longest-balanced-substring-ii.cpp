class Solution {
public:
    int longestBalanced(string s) {
        int result = 0;

        result = max(result, longestSingle(s));

        result = max(result, longestTwo(s, 'a', 'b'));
        result = max(result, longestTwo(s, 'a', 'c'));
        result = max(result, longestTwo(s, 'b', 'c'));

        result = max(result, longestThree(s));

        return result;
    }

    int longestSingle(const string& s) {
        int result = 0;
        int i = 0, length = s.size();
        while (i < length) {
            int j = i;
            while (j < length && s[j] == s[i]) j++;
            result = max(result, j - i);
            i = j;
        }

        return result;
    }

    int longestTwo(const string& s, char x, char y) {
        int result = 0;
        int i = 0, length = s.size();
        while (i < length) {
            while (i < length && s[i] != x && s[i] != y) i++;

            unordered_map<int, int> pos;
            pos[0] = i - 1;
            int diff = 0;

            while (i < length && (s[i] == x || s[i] == y)) {
                diff += (s[i] == x ? 1 : -1);
                if(pos.count(diff)) result = max(result, i - pos[diff]);
                else pos[diff] = i;

                i++;
            }
        }

        return result;
    }

    int longestThree(string s) {
        map<pair<int, int>, int> firstSeen;

        int countA = 0, countB = 0, countC = 0;
        int result = 0;

        firstSeen[{0, 0}] = -1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') countA++;
            else if (s[i] == 'b') countB++;
            else countC++;

            int d1 = countA - countB;
            int d2 = countA - countC;

            pair<int, int> state = {d1, d2};

            if (firstSeen.count(state)) result = max(result, i - firstSeen[state]);
            else firstSeen[state] = i;
        }

        return result;
    }
};