class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int length = min(word1.length(), word2.length()) * 2;
        string merged = "";
        for (int i = 0, j = 0, k = 0; i < length; i++)
        {
            merged += i % 2 ? word2[k] : word1[j];
            j += i % 2 == 0;
            k += i % 2 == 1;
        }
        if (word1.length() > word2.length())
            merged += word1.substr(word2.length());
        else
            merged += word2.substr(word1.length());
        return merged;
    }
};