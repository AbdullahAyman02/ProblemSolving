class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        sort(arr.begin(), arr.end());

        int length = arr.size();
        int i = 0, j = 1;
        int minDiff = arr[j] - arr[i];

        result.push_back({arr[i], arr[j]});
        i++;
        j++;

        while(j < length) {
            int diff = arr[j] - arr[i];

            if (diff < minDiff) {
                minDiff = diff;
                result.clear();
                result.push_back({arr[i], arr[j]});
            } else if (diff == minDiff) result.push_back({arr[i], arr[j]});

            i++;
            j++;
        }

        return result;
    }
};