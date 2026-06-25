// Last updated: 6/25/2026, 11:15:13 PM
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