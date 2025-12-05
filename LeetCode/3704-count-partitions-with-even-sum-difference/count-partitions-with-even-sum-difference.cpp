class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) sum += num;
        return sum % 2 == 0 ? nums.size() - 1 : 0;
    }
};