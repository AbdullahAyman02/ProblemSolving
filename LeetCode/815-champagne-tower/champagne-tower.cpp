class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> currentRow(1, (double)poured);

        for (int r = 0; r <= query_row; r++) {
            vector<double> nextRow(r + 2, 0.0);
            bool anyOverflow = false;

            for (int c = 0; c <= r; c++) {
                if (currentRow[c] > 1.0) {
                    double excess = currentRow[c] - 1.0;
                    double splitFlow = excess / 2.0;

                    nextRow[c] += splitFlow;
                    nextRow[c + 1] += splitFlow;

                    currentRow[c] = 1.0;
                    anyOverflow = true;
                }
            }

            if (!anyOverflow && r < query_row) {
                return (r == query_row) ? currentRow[query_glass] : 0.0;
            }

            if (r != query_row) {
                currentRow = nextRow;
            }
        }

        return currentRow[query_glass];
    }
};