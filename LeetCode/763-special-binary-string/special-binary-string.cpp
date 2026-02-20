class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0, i = 0;
        vector<string> result;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '1') count++;
            else count--;
            if (count == 0) {
                result.push_back("1" + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + "0");
                i = j + 1;
            }
        }

        sort(result.begin(), result.end(), greater<string>());
        string answer = "";
        for (auto& str : result) answer += str;
        return answer;
    }
};