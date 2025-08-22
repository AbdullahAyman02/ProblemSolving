class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int height = grid.size(), width = grid[0].size();
        int smallest_row, smallest_col; smallest_row = smallest_col = INT_MAX;
        int largest_row, largest_col; largest_row = largest_col = INT_MIN;
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                if (grid[row][col] == 1)
                {
                    smallest_row = min(smallest_row, row);
                    smallest_col = min(smallest_col, col);
                    // largest_row = max(largest_row, row);
                    largest_row = row;
                    largest_col = max(largest_col, col);
                }
            }
        }

        return (largest_col - smallest_col + 1) * (largest_row - smallest_row + 1);
    }
};