class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int length = nums.size();
        unordered_map<int, int> productsFrequency;
        int result = 0;

        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                productsFrequency[nums[i] * nums[j]]++;
            }
        }

        for (auto [product, frequency] : productsFrequency) {
            int pairs = (frequency - 1) * frequency / 2;
            result += 8 * pairs;
        }
        
        return result;
    }
};