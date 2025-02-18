class Solution {
int buildSequence(int curr, int count, string pattern, string& result) {
    if (curr != pattern.size()) {
        if (pattern[curr] == 'I')
            buildSequence(curr + 1, curr + 1, pattern, result);
        else
            count = buildSequence(curr + 1, count, pattern, result);
    }
    result += to_string(count + 1);
    return count + 1;
}

public:
    string smallestNumber(string pattern) {
        string result = "";

        buildSequence(0, 0, pattern, result);

        reverse(result.begin(), result.end());
        
        return result;
    }
};