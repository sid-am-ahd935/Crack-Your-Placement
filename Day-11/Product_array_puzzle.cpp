class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        unsigned long long int allProduct = 1;
        bool hasZero = false;
        for(int n:nums) {
            if(n == 0 && hasZero == false) {
                hasZero = true;
                continue;
            }
            allProduct *= n;
        }
        vector<long long int> res;
        
        if(hasZero == true) {
            for(int n:nums) {
                res.push_back(n == 0 ? allProduct : 0);
            }
        } else {
            for(int n:nums) {
                res.push_back(allProduct/n);
            }
        }
        
        return res;
    }
};
