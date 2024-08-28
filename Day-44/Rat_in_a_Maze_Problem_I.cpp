
class Solution {
  public:
    void func(int row, int col, vector<vector<int>> &mat, int n, vector<string>& ans, string path){

        if(row==n-1&&col==n-1){
            ans.push_back(path);
            return;
        }
        
        mat[row][col]=0;
        
        if(row>0 && mat[row-1][col]==1){
            func(row-1, col, mat, n, ans, path+"U");
        }
        if(row<n-1 && mat[row+1][col]==1){
            func(row+1,col, mat, n, ans, path+"D");
        }
        if(col<n-1 && mat[row][col+1]==1){
            func(row, col+1, mat, n, ans, path+"R");
        }
        if(col>0 && mat[row][col-1]==1){
            func(row, col-1, mat, n, ans, path+"L");
        }
        
        mat[row][col]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        int n=mat.size();
        vector<string> ans;
        
        if(mat[0][0]==0||mat[n-1][n-1]!=1){
            return {"-1"};
        }
        
        func(0,0,mat,n,ans,"");
        
        if(ans.empty()){
            return {"-1"};
        }
        
        return ans;
    }
};
