class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<bool> numbers(101, false);
        for (int i = nums.size() - 1; i >= 0; --i) 
            if (numbers[nums[i]])
                return (i / 3) + 1;
            else
                numbers[nums[i]] = true;
        return 0;
    }
};