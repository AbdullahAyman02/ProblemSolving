class Solution {
    int sumDigits(int x) {
        int s = 0;
        while (x != 0) {
            s += x % 10;
            x = x / 10;
        }
        return s;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> map;
        int maximum = -1;
        for (auto num : nums) {
            int sum_digits = sumDigits(num);
            auto it = map.find(sum_digits);
            if (map.find(sum_digits) != map.end()) {
                maximum = max(maximum, it->second + num);
                map[sum_digits] = max(num, it->second);
            }
            else
                map[sum_digits] = num;
        }
        return maximum;
    }
};