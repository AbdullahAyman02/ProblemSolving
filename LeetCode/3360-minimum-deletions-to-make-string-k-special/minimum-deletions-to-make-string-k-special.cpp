class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> frequencies;
        for (auto c : word) frequencies[c]++;

        int result = word.size();
        for (auto &[charA, frequencyA] : frequencies) {
            int deleted = 0;
            for (auto &[charB, frequencyB] : frequencies) {
                if (frequencyA > frequencyB)
                    deleted += frequencyB;
                else if (frequencyB > frequencyA + k)
                    deleted += frequencyB - frequencyA - k;
            }
            result = min(result, deleted);
        }
        return result;
    }
};