class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        vector<int> leftSmall(heights.size(), 0), rightSmall(heights.size(), 0);
        stack<int> left, right;

        for(int i=0; i<heights.size(); i++) {
            while(!left.empty() && heights[i] <= heights[left.top()]) left.pop();
            if(left.empty()) {
                leftSmall[i] = 0;
            } else {
                leftSmall[i] = left.top()+1;
            }
            left.push(i);
        }

        for(int i=heights.size()-1; i>=0; i--) {
            while(!right.empty() && heights[i] <= heights[right.top()]) right.pop();
            if(right.empty()) {
                rightSmall[i] = heights.size()-1;
            } else {
                rightSmall[i] = right.top()-1;
            }
            right.push(i);
        }

        // for(int h:leftSmall) {
        //     cout << h << ", ";
        // } cout << endl;

        // for(int h:rightSmall) {
        //     cout << h << ", ";
        // } cout << endl;

        for(int i=0; i<heights.size(); i++) {
            maxArea = max(maxArea, (rightSmall[i]-leftSmall[i]+1)*heights[i]);
            // cout << heights[i] << "(" << leftSmall[i] << "," << rightSmall[i] << ") = " << (rightSmall[i]-leftSmall[i]+1) << "*" << min(heights[leftSmall[i]], heights[rightSmall[i]]) << " = " << maxArea << endl;
        }

        return maxArea;
    }
};
