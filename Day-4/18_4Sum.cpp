class Solution {
private:
    bool equals(vector<int> a, vector<int> b) {
        for(int i=0; i<min(a.size(), b.size()); i++) {
            if(a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) {
            return {};
        }
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-3; i++) {
            for(int j=i+1; j<nums.size()-2; j++) {
                int k = j+1, l = nums.size()-1;

                while(k < l) {
                    long sum = long(nums[i]) + long(nums[j]) + long(nums[k]) + long(nums[l]);
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};  
                     
                    if(sum < target) {
                        k++;
                    } else if(sum > target){
                        l--;
                    } else {
                        if(find(res.begin(),res.end(),temp)==res.end()) {
                            res.push_back(temp);
                        }
                        k++;
                        l--;
                    }
                }
            }
        }

        return res;
    }
};
