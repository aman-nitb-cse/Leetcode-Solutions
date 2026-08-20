// Last updated: 8/20/2026, 9:07:20 PM
class RandomizedCollection {
    vector<int> nums;
    unordered_map<int, unordered_set<int>> index;

public:
    RandomizedCollection() {
        srand(time(0));
    }

    bool insert(int val) {
        bool first = index[val].empty();

        nums.push_back(val);
        index[val].insert(nums.size() - 1);

        return first;
    }

    bool remove(int val) {
        if(index[val].empty())
            return false;

        int idx = *index[val].begin();
        index[val].erase(idx);

        int last = nums.back();

        if(idx != nums.size() - 1) {
            nums[idx] = last;

            index[last].erase(nums.size() - 1);
            index[last].insert(idx);
        }

        nums.pop_back();

        if(index[val].empty())
            index.erase(val);

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};