class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int length = grid.size();
        for (int i = 0; i < length; i++) {
            vector<int> temp;
            for (int j = 0; i + j < length; j++)
                temp.push_back(grid[i + j][j]);
            sort(temp.begin(), temp.end(), greater<int> ());
            for (int j = 0; i + j < length; j++)
                grid[i + j][j] = temp[j];
        }

        for (int j = 1; j < length; j++) {
            vector<int> temp;
            for (int i = 0; j + i < length; i++) 
                temp.push_back(grid[i][j + i]);
            sort(temp.begin(), temp.end());
            for (int i = 0; j + i < length; i++)
                grid[i][j + i] = temp[i];
        }

        return grid;
    }
};