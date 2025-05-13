class Solution {
    static const int MOD = 1000000007;

public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> count(26, 0);
        for (auto c : s)
            count[c - 'a']++;
        
        int index_z = 25;
        for (int i = 0; i < t; i++) {
            int next = (index_z + 1) % 26;
            count[next] = (count[next] + count[index_z]) % MOD;
            index_z = ((index_z - 1) + 26) % 26;
        }

        int result = 0;
        for (int c : count)
            result = (c + result) % MOD;

        return result;
    }
};