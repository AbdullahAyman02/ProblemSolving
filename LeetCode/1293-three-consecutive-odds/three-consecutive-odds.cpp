class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 0, length = arr.size(); i < length - 2; i++)
            if (arr[i] % 2 != 0)
                if (arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0)
                    return true;
        return false;
    }
};