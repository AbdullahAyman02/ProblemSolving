class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int result = 0;
        unordered_map<int, int> frequency;
        for (int start = 0, end = 0, size = fruits.size(); end < size; end++) {
            ++frequency[fruits[end]];

            while (frequency.size() > 2) {
                frequency[fruits[start]]--;
                if (frequency[fruits[start]] == 0)
                    frequency.erase(fruits[start]);
                start++;
            }

            result = max(result, end - start + 1);
        }
        return result;
    }
};