// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>> ans;
//         sort(nums.begin(),nums.end());

//         ans.push_back(nums);

//         while(next_permutation(nums.begin(),nums.end())) {
//             ans.push_back(nums);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> Ans;
    
    void Helper(vector<int>& output, string& input) {
        // Base case
        if (input.size() == 0) {
            Ans.push_back(output);
            return;
        }
        
        // Recursive case
        unordered_set<char> set;
        for (int i = 0; i < input.size(); i++) {
            if (set.find(input[i]) == set.end()) {
                string newIp = input.substr(0, i) + input.substr(i + 1);
                output.push_back(input[i] - '0');
                set.insert(input[i]);
                Helper(output, newIp);
                output.pop_back();
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // Convert nums to string
        string input = "";
        for (int num : nums) 
            input.push_back(num + '0');
        
        // Initialize output vector
        vector<int> output;
        
        // Generate permutations
        Helper(output, input);
        
        return Ans;
    }
};
