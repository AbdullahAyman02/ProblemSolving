class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int result = 0;

        for (int i = 0, length = words.size(); i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (words[j].rfind(words[i], 0) == 0 && words[j].find(words[i], words[j].size() - words[i].size()) != std::string::npos)
                    result++;
            }
        }

        return result;
    }
};