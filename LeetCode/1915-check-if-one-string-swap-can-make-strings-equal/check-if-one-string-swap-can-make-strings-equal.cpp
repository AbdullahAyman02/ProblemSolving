class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i1 = -1, i2 = -1;
        for (int i = 0, length = s1.size(); i < length; i++) {
            if (s1[i] != s2[i]) {
                if (i1 != -1 && i2 != -1)
                    return false;
                if (i1 != -1)
                    i2 = i;
                else
                    i1 = i;
            }
        }
        if (i2 == -1)
            if (i1 == -1)
                return true;
            else
                return false;
        return s1[i1] == s2[i2] && s1[i2] == s2[i1];
    }
};