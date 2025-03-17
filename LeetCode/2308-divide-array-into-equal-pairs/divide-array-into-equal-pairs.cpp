class Solution {
public:
    bool divideArray(vector<int>& nums) {
        if (nums.size() % 2 != 0)
            return false;
        vector<int> freqArray(501, 0);
        for (auto& num : nums)
            freqArray[num]++;
        for (auto& num : freqArray)
            if (num % 2 != 0)
                return false;
        return true;
    }
};