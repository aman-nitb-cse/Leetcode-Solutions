// Last updated: 11/6/2026, 5:00:00 AM
class Solution {
public:
    int countStudents(vector<int>& stu, vector<int>& sand) {
        unordered_map <int, int> hash;
        hash[0] = 0; hash[1] = 0;
        for(int &i : stu) hash[i]++;
        for(int i = 0; i < sand.size(); i++){
            if(hash[sand[i]] == 0) return stu.size() - i;
            hash[sand[i]]--;
        }
        return 0;
    }
};