class Solution {
public:
    vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> v(words.size(), 0);
        int i = 0, sum = 0;
        for (auto word : words)
        {
            if(find(vowels.begin(), vowels.end(), word.front()) != vowels.end() && find(vowels.begin(), vowels.end(), word.back()) != vowels.end())
                sum++;
            v[i] = sum;
            i++;
        }
        vector<int> output(queries.size(), 0);
        int k = 0;
        for (auto &query : queries)
        {
            int start = query[0], end = query[1];
            output[k] = v[end] - (start == 0 ? 0 : v[start - 1]);
            k++;
        }
        return output;
    }
};