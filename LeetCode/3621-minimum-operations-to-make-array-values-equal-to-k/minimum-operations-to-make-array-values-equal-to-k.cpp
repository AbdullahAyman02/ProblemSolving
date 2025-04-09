class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> set;
        for (auto num : nums)
            if (num < k)
                return -1;
            else if (num > k)
                set.insert(num);
        return set.size();
    }
};