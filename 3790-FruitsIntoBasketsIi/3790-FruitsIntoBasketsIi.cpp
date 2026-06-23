// Last updated: 6/24/2026, 3:29:54 AM
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