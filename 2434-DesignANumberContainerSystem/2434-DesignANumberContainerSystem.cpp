// Last updated: 6/25/2026, 11:11:59 PM
class NumberContainers {
public:
    unordered_map<int, set<int>> idx; // val -> index
    unordered_map<int,int> value; // index -> val 

    void change(int index, int val) {
        if(value.count(index)){

            idx[value[index]].erase(index);
            
        }

        idx[val].insert(index);
        value[index] = val;
    }
    
    int find(int val) {
        auto &st = idx[val];

        return st.empty() ? -1 : *st.begin();
    }
};