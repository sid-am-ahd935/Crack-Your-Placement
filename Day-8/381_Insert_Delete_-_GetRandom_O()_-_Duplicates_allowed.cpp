#include <cstdlib>
class RandomizedCollection {
private:
    unordered_map<int, vector<int>> numbers;
    vector<int> nums;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool flag = numbers.find(val) == numbers.end();
        nums.push_back(val);
        numbers[val].push_back(nums.size()-1);
        
        // for(int n:nums) {
        //     cout << n << ", ";
        // } cout << endl;

        return flag;
    }
    
    bool remove(int val) {
        bool flag = numbers.find(val) != numbers.end();
        if(flag) {
            if(nums[nums.size()-1] == val) {
                numbers[val].pop_back();
                nums.pop_back();
            } else {
                
                int index = numbers[val].back();
                numbers[val].pop_back();

                int swapper = nums[nums.size()-1];
                numbers[swapper].pop_back();
                numbers[swapper].push_back(index);
                sort(numbers[swapper].begin(), numbers[swapper].end());        
                // To even remove this O(K logK) complexity, where larger value increases TC decreases unsortedness, hence decreases TC, the iterators of indexes of nums can be stored in nums itself, using pairs
                // Such that, numbers[nums.first (val)][nums.second (index of this nums index in numbers)] = i

                swap(nums[nums.size()-1], nums[index]);
                nums.pop_back();
            }
            if(numbers[val].empty()) numbers.erase(val);
        }
        return flag;
    }
    
    int getRandom() {
        int choose = rand()%nums.size();
        return nums[choose];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
