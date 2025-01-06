class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> out(boxes.length(), 0);
        int sum = 0;
        for(int i = 0, length = boxes.length(); i < length; i++)
        {
            sum = 0;
            for(int j = 0; j < length; j++)
            {
                if(j == i)
                    continue;
                if(boxes[j] == '1')
                    sum += abs(j - i);
            }
            out[i] = sum;
        }
        return out;
    }
};