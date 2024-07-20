class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Did this a while ago, basically, if a number appears more times than half, and even if decrease it frequency each time it did not occur, it will still be 1 or more than 1
        // Let repeating nmber = a
        // count[a]++ if a else count[a]--
        // count [a] > 0 because no of count-- < no of count++

        int num = nums[0];
        int count = 1;
        for(int i=1; i<nums.size(); i++) {
            if(num == nums[i]) {
                count++;
            } else {
                count--;
            }

            if(count == 0) {
                num = nums[i];
                count = 1;
            }
        }

        return num;
    }
};
