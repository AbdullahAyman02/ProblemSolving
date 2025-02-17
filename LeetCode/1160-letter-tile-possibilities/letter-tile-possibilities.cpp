class Solution {
    int recPossibilities(vector<int>& freqArray) {
        int result = 0;
        for (int i = 0; i < 26; i++) {
            if (freqArray[i]) {
                result++;
                freqArray[i]--;
                result += recPossibilities(freqArray);
                freqArray[i]++;
            }
        }
        return result;
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> freqArray(26, 0);
        for (auto tile : tiles) freqArray[tile - 'A']++;
        return recPossibilities(freqArray);
    }
};