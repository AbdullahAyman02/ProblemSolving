class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        bool flag;
        long long count = 0; 
        int length1, length2 = s.size();
        for(auto& word: words)
        {
            flag = true;
            length1 = word.size();
            if(length1 > length2)
                continue;
            for(int i = 0; i < min(length1, length2); i++)
            {
                if(word[i] != s[i])
                {   
                    flag = false;
                    break;
                }
            }
            if(flag)
                count++;
        }
        return count;
    }
};