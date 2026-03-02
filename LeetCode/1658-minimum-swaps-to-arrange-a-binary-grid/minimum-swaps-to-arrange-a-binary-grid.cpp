class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int streak = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) streak++;
                else break;
            }
            arr[i] = streak;
        }

        int steps = 0;

        for (int i = 0; i < n; i++) {
            int need = n - i - 1;
            int j = i;
            while (j < n && arr[j] < need) j++;
            if (j == n) return -1;
            while (j > i) {
                swap(arr[j], arr[j - 1]);
                steps++;
                j--;
            }

            steps += j - i;
            int val = arr[j];
            arr.erase(arr.begin() + j);
            arr.insert(arr.begin() + i, val);
        }

        return steps;
    }
};