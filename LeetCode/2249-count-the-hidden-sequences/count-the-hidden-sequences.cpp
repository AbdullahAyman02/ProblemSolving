class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int x = 0, y = 0, current = 0;
        for (auto difference : differences) {
            current += difference;
            x = min(x, current);
            y = max(y, current);
            if (y - x > upper - lower)
                return 0;
        }

        return (upper - lower) - (y - x) + 1;
    }
};