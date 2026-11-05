// Last updated: 11/6/2026, 4:43:15 AM
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& F, vector<int>& B) {

        int n = F.size(), cnt = 0;

        for(int i = 0; i < n; i++){
            bool ok = false;
            for(int j = 0; j < n; j++){
                if(B[j] >= F[i]){
                    B[j] = -1;
                    ok = true;
                    break;
                }
            }

            if(!ok) cnt++;
        }

        return cnt;
    }
};