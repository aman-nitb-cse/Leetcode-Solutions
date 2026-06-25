// Last updated: 6/25/2026, 11:16:36 PM
class ProductOfNumbers {
public:
    vector<int> v;
    void add(int num) {
        if(num == 0) v.clear();
        else if(v.empty()) v.push_back(num);
        else v.push_back(v.back() * num);
    }
    
    int getProduct(int k) {
        if(k > v.size()) return 0;
        if(k == v.size()) return v.back();
        return v[v.size() - 1] / v[v.size() - k - 1];
    }
};