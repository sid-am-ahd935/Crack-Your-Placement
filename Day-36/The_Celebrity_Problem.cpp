class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        int i = 0 , j = n-1;
        
        while(i < j){
            if(mat[i][j] == 1){
                i++;
            }
            else{
                j--;
            }
            
        }
        int candidate = i;
        
        for(int k=0;k<n;k++){
            if(k != candidate){
                if(mat[candidate][k] == 1 || mat[k][candidate] == 0){
                    return -1;
                }
            }
        }
        return candidate;
    }
};
