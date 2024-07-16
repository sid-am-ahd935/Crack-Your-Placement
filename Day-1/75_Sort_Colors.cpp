class Solution {
public:
    void sortColors(vector<int>& nums) {
        // We will make 2 pointers, one for keeping 0 on the left, and another for keeping 2 on the right, doing this will make 1 automatically come in the middle
        // Both the indexes are for adding the next 0/2;
        int zero = 0;
        int two = nums.size()-1;

        // The pointer which is going to traverse the whole thing
        int i = 0;

        while(i <= two) {
            if(i < zero) {
                i++;
            } else if(nums[two] == 2) {
                two--;
            } else if(nums[zero] == 0) {
                zero++;
            } else if(nums[i] == 0) {
                swap(nums[i], nums[zero]);
                zero++;
            } else if(nums[i] == 2) {
                swap(nums[i], nums[two]);
                two--;
            } else {
                i++;
            }
        }

        return;
    }
};
