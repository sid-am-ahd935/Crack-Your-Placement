class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Shifting the contents of nums1 to rightmost
        for(int i=m+n-1; i>=n; i--) {
            nums1[i] = nums1[i-n];
        }
        // for(int i:nums1) {
        //     cout << i << ", ";
        // } cout << endl;
        int p1 = n, p2 = 0, p = 0;
        while(p1 < m+n && p2 < n) {
            if(nums1[p1] < nums2[p2]) {
                nums1[p] = nums1[p1];
                p++;
                p1++;
            } else {
                nums1[p] = nums2[p2];
                p++;
                p2++;
            }
        }
        while(p1 < m+n) {
            nums1[p] = nums1[p1];
            p++;
            p1++;
        }
        while(p2 < n) {
            nums1[p] = nums2[p2];
            p++;
            p2++;
        }

        return;
    }
};
