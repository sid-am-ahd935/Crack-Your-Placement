class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Watched mutiple videos without seeing the code, have to revise and practice a bit to understand more intuitively
        // Got stuck in an edge case
        // Again
        // Was having difficulty with negative remainders, so referred to video fully, to get around this edge case
        // CHanging negative remainders to positive remainders using 7n - 4 = 7n - 4 + 7 - 7 = 7(n-1) + 7 - 4 = 7(n-1) + 3 which is equivalent
        int sum = 0, count = 0;
        unordered_map<int, int> rems;
        rems[0] = 1;

        for(int n:nums) {
            sum += n;
            int mod = ((sum % k) + k) % k;


            if(rems.find(mod) != rems.end()) {
                count += rems[mod];
            }
            rems[mod]++;
        }

        return count;
    }
};
