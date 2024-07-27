class Solution {
public:
    int ceilSearch(int arr[], int n, int x) {
        int pos = -1;
        int s = 0, e = n-1;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(arr[mid] >= x) {
                pos = mid;
                e = mid-1;
            } else {
                s = mid + 1;
            }
        }
        
        return pos;
    }
};
