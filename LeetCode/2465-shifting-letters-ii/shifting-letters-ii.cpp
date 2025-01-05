class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int length = s.size();
        vector<int> diffArray(length, 0);
        for(auto shift : shifts)
        {
            if (shift[2] == 1)
            {
                diffArray[shift[0]]++;
                if (shift[1] + 1 < length)
                    diffArray[shift[1] + 1]--;
            }
            else
            {
                diffArray[shift[0]]--;
                if (shift[1] + 1 < length)
                    diffArray[shift[1] + 1]++;
            }
        }

        string result(length, ' ');
        int numberOfShifts = 0;
        for (int i = 0; i < length; i++)
        {
            numberOfShifts = (numberOfShifts + diffArray[i]) % 26;
            numberOfShifts = numberOfShifts < 0 ? numberOfShifts + 26 : numberOfShifts;
            result[i] = 'a' + (s[i] - 'a' + numberOfShifts) % 26;
        }
        return result;
    }
};