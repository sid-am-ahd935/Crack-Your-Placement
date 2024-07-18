class Solution {
public:
    int maxArea(vector<int>& height) {
        // I think I have done this too...
        // Two pointer  (just remembered this doesn't work. Just watched a video it is the one that works!!)

        int area = INT_MIN;
        int p1 = 0, p2 = height.size()-1;

        while(p1 < p2) {
            int a = height[p1], b = height[p2];
            area = max(area, (p2-p1)*min(a, b));
            if(a < b) {
                p1++;
            } else {
                if(a == b && height[p1+1] < height[p2-1]) {
                    // Choosing next 
                    p1++;
                } else {
                    p2--;
                }
            }
        }

        return area;
    }
};
