class Solution {
  private:
    void choose(vector<int> &arr, unordered_map<int, int> &mark, map<vector<int>, int> &res, vector<int>& temp, vector<vector<int>>& ans) {
        if(temp.size() == arr.size()) {
            if(res.find(temp) == res.end()) {
                res[temp] = 1;
                ans.push_back(temp);
            }
            return;
        }
        
        for(int i=0; i<arr.size(); i++) {
            if(mark[i] == false) {
                temp.push_back(arr[i]);
                mark[i] = true;
                choose(arr, mark, res, temp, ans);
                temp.pop_back();
                mark[i] = false;
            }
        }
    }
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        unordered_map<int, int> mark;
        map<vector<int>, int> res;
        vector<int> temp;
        vector<vector<int>> ans;
        
        // sort(ans.begin(), ans.end());
        sort(arr.begin(), arr.end());
        
        choose(arr, mark, res, temp, ans);
        
        return ans;
    }
};
