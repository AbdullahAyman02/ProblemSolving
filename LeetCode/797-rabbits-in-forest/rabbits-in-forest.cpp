class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> map;
        int result = 0;
        
        for (auto i : answers) map[i]++;

        for (auto& item : map)
            result += ceil((double)item.second / (item.first + 1)) * (item.first + 1);
        
        return result;
    }
};