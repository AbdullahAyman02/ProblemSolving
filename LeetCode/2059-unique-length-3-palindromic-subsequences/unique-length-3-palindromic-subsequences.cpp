class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for(auto c : s)
            letters.insert(c);
        int result = 0;
        for(auto letter : letters)
        {
            int i, j, length = s.size();
            for (i = 0; i < length; i++)
                if(s[i] == letter)
                    break;
            for (j = length - 1; j >= 0; --j)
                if(s[j] == letter)
                    break;
            unordered_set<char> between;
            for(int k = i + 1; k < j; k++)
                between.insert(s[k]);
            result += between.size();
        }
        return result;
    }
};