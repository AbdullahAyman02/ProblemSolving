class Solution {
public:
    string clearDigits(string s) {
        string result = "";
        for (auto c : s) {
            if (isdigit(c)) {
                if (!result.empty())
                    result.pop_back();
            }
            else
                result += c;
        }
        return result;
    }
};