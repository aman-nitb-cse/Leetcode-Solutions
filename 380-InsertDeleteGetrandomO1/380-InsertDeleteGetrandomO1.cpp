// Last updated: 8/20/2026, 9:07:23 PM
class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> index;

public:
    RandomizedSet() {
        srand(time(0));
    }

    bool insert(int val) {
        if(index.count(val))
            return false;

        index[val] = nums.size();
        nums.push_back(val);

        return true;
    }

    bool remove(int val) {
        if(!index.count(val))
            return false;

        int idx = index[val];
        int last = nums.back();

        nums[idx] = last;
        index[last] = idx;

        nums.pop_back();
        index.erase(val);

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};