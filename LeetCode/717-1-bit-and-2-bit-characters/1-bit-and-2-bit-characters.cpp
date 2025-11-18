class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int j = bits.size() - 1; if (j == 0) return true;
        // Last element is 1 -> 11
        if (bits[j--] == 1)
            return false;
        // Last element is 0: could be one bit 0, or two bits 10
        // If one bit 0, before it could be 10 or 11
        // To check 10 -> check if previous = 0
        if (bits[j] == 0)
            return true;
        // Otherwise, check the number of ones before the final 0; if odd, then final zero is part of two bits 10, if even then it is one bit 0 and the previous 1 is part of two bits 11
        int count_ones = 0;
        while(j >= 0) if (bits[j--] == 1) count_ones++; else break;
        return !(count_ones % 2);
    }
};