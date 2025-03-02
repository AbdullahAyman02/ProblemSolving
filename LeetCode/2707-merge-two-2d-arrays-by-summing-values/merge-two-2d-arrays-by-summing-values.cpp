class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int ptr1 = 0, ptr2 = 0;

        vector<vector<int>> mergedArray;
        while(ptr1 < n1 && ptr2 < n2) {
            if (nums1[ptr1][0] == nums2[ptr2][0]) {
                mergedArray.push_back({nums1[ptr1][0], nums1[ptr1][1] + nums2[ptr2][1]});
                ptr1++;
                ptr2++;
            } else if (nums1[ptr1][0] < nums2[ptr2][0]) {
                mergedArray.emplace_back(nums1[ptr1]);
                ptr1++;
            } else {
                mergedArray.emplace_back(nums2[ptr2]);
                ptr2++;
            }
        }

        while (ptr1 < n1) {
            mergedArray.emplace_back(nums1[ptr1]);
            ptr1++;
        }

        while (ptr2 < n2) {
            mergedArray.emplace_back(nums2[ptr2]);
            ptr2++;
        }

        return mergedArray;
    }
};