class Solution {
public:
    int findNumbers(vector<int>& nums) {
        string temp;
        int result = 0;
        for (auto num : nums) {
            temp = to_string(num);
            if (temp.length() % 2 == 0)
                result++;
        }
        return result;
    }
};