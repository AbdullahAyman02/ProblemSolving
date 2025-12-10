class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int length = complexity.size();
        if (*min_element(complexity.begin() + 1, complexity.end()) <= complexity[0])
            return 0;

        int MOD = 1e9 + 7;
        int result = 1;
        for (int i = 2; i < length; i++)
            result = static_cast<long long> (result) * i % MOD;
        
        return result;
    }
};