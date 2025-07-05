class Solution {
public:
    int findLucky(vector<int>& arr) {
        int result = -1;
        unordered_map<int, int> map;
        for (const auto& num : arr) map[num]++;
        for (auto& [num, freq] : map)
            if (num == freq)
                result = max(result, num);
        return result;
    }
};