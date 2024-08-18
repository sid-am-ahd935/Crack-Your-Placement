class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2!=0)return 0;
        int w=sum/2;
        int t[n+1][w+1];//memoization in DP
        for(int i=0;i<=n;i++){
            for(int j=0;j<=w;j++){
                if(i==0){
                    t[i][j]=false;   //Initialization of DP
                }
                if(j==0){
                    t[i][j]=true;
                }
            }
        }
        //populating the dp
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        if(t[n][w]==1)return 1;
        return 0;
        
    }
};
