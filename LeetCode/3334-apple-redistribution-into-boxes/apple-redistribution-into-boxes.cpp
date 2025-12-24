class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = reduce(apple.begin(), apple.end());
        int result = 0;
        while (sum > 0) {
            auto it = max_element(capacity.begin(), capacity.end());
            sum -= *it;
            capacity.erase(it);
            result++;
        }
        return result;
    }
};