class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> partitionSizes;
        int lastOccurence[26] = {0}, firstOccurence[26] = {0};
        int partitionStart = 0, partitionEnd = 0;

        for (int i = 0; i < s.length(); i++) 
            lastOccurence[s[i] - 'a'] = i;
        
        for (int i = 0; i < s.length(); i++) {
            if (!firstOccurence[s[i] - 'a']) 
                firstOccurence[s[i] - 'a'] = i;

            if (partitionEnd < firstOccurence[s[i] - 'a']) {
                partitionSizes.push_back(partitionEnd - partitionStart + 1);
                partitionStart = i;
                partitionEnd = i;
            }

            partitionEnd = max(partitionEnd, lastOccurence[s[i] - 'a']);
        }

        if (partitionEnd - partitionStart + 1 > 0)
            partitionSizes.push_back(partitionEnd - partitionStart + 1);

        return partitionSizes;
    }
};