class Solution {
public:
    string getHappyString(int n, int k) {
        int sz = pow(2, n - 1);
        if (3 * sz < k) return "";

        string result = "";
        if (k <= sz) result += 'a';
        else if (k <= 2 * sz) {
            result += 'b';
            k -= sz;
        }
        else {
            result += 'c';
            k -= 2 * sz;
        }

        string opts[] = { "bc", "ac", "ab" };
        for (int i = 1; i < n; i++) {
            sz /= 2;
            string& ch = opts[result.back() - 'a'];
            if (k <= sz) result += ch[0];
            else {
                result += ch[1];
                k -= sz;
            }
        }

        return result;
    }
};