class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = INT_MAX;
        int top, bottom;
        bool valid;
        for (int domino = 1; domino <= 6; domino++) {
            top = 0, bottom = 0;
            valid = true;

            for (int i = 0, length = tops.size(); i < length; i++) {
                if (tops[i] != domino && bottoms[i] != domino) {
                    valid = false;
                    break;
                }
                if (tops[i] != domino) top++;
                if (bottoms[i] != domino) bottom++;
            }

            if (valid)
                result = min(result, min(top, bottom));
        }

        return result == INT_MAX ? -1 : result;
    }
};