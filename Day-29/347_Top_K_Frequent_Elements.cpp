class MyComparator {
public:
    int operator()(std::pair<int, int>& p1, std::pair<int, int>& p2) {
        return (p1.second > p2.second);
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // find the frequency of each number
        map<int, int> numFrequencyMap;
        for (int num = 0; num < nums.size(); num++) {
            numFrequencyMap[nums[num]] = numFrequencyMap[nums[num]] + 1;
        }
        typedef pair<int, int> pi;
        priority_queue<pi, vector<pi>, MyComparator> topKElements;
        // go through all numbers of the numFrequencyMap
        // and push them in the topKElements, which will have
        // top k frequent numbers. If the heap size is more than k,
        // we remove the smallest(top) number
        for (auto& it : numFrequencyMap) {
            topKElements.push(make_pair(it.first, it.second));
            if (topKElements.size() > k) {
                topKElements.pop();
            }
        }

        // create a list of top k numbers
        vector<int> topNumbers = {};
        while (topKElements.size() > 0) {
            pair<int, int> p = topKElements.top();
            topKElements.pop();
            topNumbers.push_back(p.first);
        }
        return topNumbers;
    }
};
