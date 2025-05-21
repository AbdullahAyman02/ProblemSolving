class Solution {
    void printMatrix(vector<vector<int>>& matrix) {
        for (auto& row : matrix) {
            for (auto& col : row)
                cout << col << " ";
            cout << '\n';
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int, int>> indices;
        int numRows = matrix.size(), numCols = matrix[0].size();
        for (int row = 0; row < numRows; row++)
            for (int col = 0; col < numCols; col++)
                if (matrix[row][col] == 0) indices.insert({row, col});
        // cout << "Before: " << endl;
        // printMatrix(matrix);
        for (auto pair : indices) {
            // cout << "Index: " << pair.first << " " << pair.second << endl;
            for (int i = 0; i < numRows; i++) matrix[i][pair.second] = 0;
            for (int j = 0; j < numCols; j++) matrix[pair.first][j] = 0;
            // printMatrix(matrix);
        }
    }
};