class Solution {
public:
    int possibleStringCount(string word) {
        int result = 1;
        for (int i = 1, length = word.size(); i < length; i++)
            if (word[i] == word[i - 1]) result++;
        return result;
    }
};