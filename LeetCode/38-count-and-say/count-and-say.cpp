class Solution {
    void countAndDontSay(int index, int n, string& result) {
        if (index >= n)
            return;
        
        string prev_result = result;
        result = "";
        int left = 0, count = 0;
        for (int right = 0; right < prev_result.size(); right++) {
            if (prev_result[left] != prev_result[right]) {
                result += to_string(count) + prev_result[left];
                left = right;
                count = 1;
            } else
                count++;
        }

        result += to_string(count) + prev_result[left];
        return countAndDontSay(index + 1, n, result);
    }
public:
    string countAndSay(int n) {
        string result = "1";
        countAndDontSay(1, n, result);
        return result;
    }
};