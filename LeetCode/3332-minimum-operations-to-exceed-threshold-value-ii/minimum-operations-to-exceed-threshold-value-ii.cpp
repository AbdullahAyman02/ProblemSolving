class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> min_heap(nums.begin(), nums.end());
        int result = 0;

        while (min_heap.top() < k) {
            long long x = min_heap.top();
            min_heap.pop();
            long long y = min_heap.top();
            min_heap.pop();
            min_heap.push(min(x, y) * 2 + max(x, y));

            result++;
        }
        
        return result;
    }
};