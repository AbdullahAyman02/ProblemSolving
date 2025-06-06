class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        int i = 0;
        for (auto& word : words) {
            if (word.find(x) != string::npos)
                result.emplace_back(i);
            i++;
        }
        return result;
    }
};