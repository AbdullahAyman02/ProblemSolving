class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int result = 0, t = 0;
        for (int i = 0, length = startTime.size(); i < length; i++) {
            t += endTime[i] - startTime[i];
            int left = i <= k - 1 ? 0 : endTime[i - k];
            int right = i == length - 1 ? eventTime : startTime[i + 1];
            result = max(result, right - left - t);
            if (i >= k - 1) t -= endTime[i - k + 1] - startTime[i - k + 1];
        }
        return result;
    }
};