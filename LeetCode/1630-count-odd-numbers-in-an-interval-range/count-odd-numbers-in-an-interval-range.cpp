class Solution {
public:
    int countOdds(int low, int high) {
        // bool flag = (low % 2) && (high % 2);
        // return (high - low + 1) / 2;
        return (high + 1) / 2 - (low / 2);
    }
};