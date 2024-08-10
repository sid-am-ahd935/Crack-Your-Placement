class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arrPos(n);
        for (int i = 0; i < n; ++i) {
            arrPos[i] = {nums[i], i};
        }
    
        // Sort the array by array element values to get the correct positions
        sort(arrPos.begin(), arrPos.end());
    
        // To keep track of visited elements
        vector<bool> visited(n, false);
    
        int swaps = 0;
    
        for (int i = 0; i < n; ++i) {
            // If the element is already visited or already in the correct position
            if (visited[i] || arrPos[i].second == i) {
                continue;
            }
    
            // Calculate the size of the cycle
            int cycleSize = 0;
            int x = i;
    
            while (!visited[x]) {
                visited[x] = true;
                x = arrPos[x].second;
                cycleSize++;
            }
    
            // If there is a cycle of size k, we need k-1 swaps to sort it
            if (cycleSize > 0) {
                swaps += (cycleSize - 1);
            }
        }
    
        return swaps;
    }
};
