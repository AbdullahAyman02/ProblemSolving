class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int length = arr.size(), result = 0;
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                for (int k = j + 1; k < length; k++) {
                    if (abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b &&
                        abs(arr[i] - arr[k]) <= c) {
                            result++;
                        }
                }
            }
        }

        return result;
    }
};