class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> freqArray;
        for (char c : s)
            freqArray[c]++;
        
        int count = 0;
        for (auto &pair : freqArray)
        {
            int freq = pair.second;
            if (freq % 2 == 1)
                count += freq - 1;
            else
                count += freq - 2;
        }

        return s.length() - count;
    }
};