class Solution{
  public:
    vector<vector<int>> sumZeroMatrix(vector<vector<int>>mat){
      //Code Here
        int n= mat.size(), m= mat[0].size();
        
        int sr=-1, sc=-1, er=-1, ec=-1;
        for (int col=0; col<m; col++){
            //ps that stores the curr prefix sum for all the rows
            //eg ps[1] will store sum of all elements such that j>=col & i==1
            vector<int>ps(n,0);
            
            for (int j=col; j<m; j++){
                
                for (int i=0; i<n; i++)
                    ps[i]= ps[i]+mat[i][j];
                
                //map corresponds to the prefix sum in ps array to its rowInd
                unordered_map<int,int>mp;
                //if the prefix sum itself is zero
                int preSum=0;
                for (int i=0; i<n; i++){
                    
                    preSum+=ps[i];
                    int vert= (er==-1) ? 0 : (er-sr+1);
                    int hori= (ec-sc+1);
                    int cHori= (j-col+1);
                    int cVert;
                    
                    
                    if (preSum==0){
                        cVert= i+1;
                        int size= vert*hori;
                        int cSize= cVert*cHori;
                        
                        if (cSize>size){
                            sr= 0;
                            er= i;
                            sc= col;
                            ec= j;
                        }
                        
                    } else if (mp.find(preSum)!=mp.end()){
                        cVert= (i-mp[preSum]);
                        
                        int size= vert*hori;
                        int cSize= cVert*cHori;
                        
                        if (cSize>size){
                            sr= mp[preSum]+1;
                            er= i;
                            sc= col;
                            ec= j;
                        }
                    } else {
                        mp[preSum]= i;
                    }
                }  
                mp.clear();
            }
        }
        
        vector<vector<int>>res;
        for (int i= sr; i<=er; i++){
            vector<int>psh;
            for (int j=sc; j<=ec; j++)
                psh.push_back(mat[i][j]);
            res.push_back(psh);
        }
        
        return res;
    }
};
