class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int length = A.size();
        vector<int> commonArray(length), freqArray(length + 1, 0);
        int commonCount = 0;

        for (int i = 0; i < length; i++)
        {
            if (++freqArray[A[i]] == 2)
                commonCount++;
            if (++freqArray[B[i]] == 2)
                commonCount++;
            commonArray[i] = commonCount;
        }
        return commonArray;
    }
};