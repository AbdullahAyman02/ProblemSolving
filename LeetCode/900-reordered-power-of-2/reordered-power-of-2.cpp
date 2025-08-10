class Solution {
    string countDigits(int x) {
        string s = to_string(x);
        sort(s.begin(), s.end());
        return s;
    }
public:
    bool reorderedPowerOf2(int n) {
        string target = countDigits(n);
        for (int i = 0; i < 32; i++)
            if (countDigits(1 << i) == target)
                return true;
        return false;
    }
};