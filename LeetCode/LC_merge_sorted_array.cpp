class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)
            return;
        vector<int> temp(m + n);
        int i = 0, j = 0, k = 0;
        while(true)
        {
            if(i == m || j == n)
                break;
            if(nums1[i] < nums2[j])
            {
                temp[k] = nums1[i];
                i++;
            }
            else
            {
                temp[k] = nums2[j];
                j++;
            }
            k++;
        }
        if(i < m)
            for(i; i < m; i++, k++)
                temp[k] = nums1[i];
        else
            for(j; j < n; j++, k++)
                temp[k] = nums2[j];
        nums1 = temp;
    }
};