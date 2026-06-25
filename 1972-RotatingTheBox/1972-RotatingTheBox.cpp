// Last updated: 6/25/2026, 11:14:28 PM
class Solution {
public:
    vector<vector<char>> rotate90Clockwise(vector<vector<char>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<char>> res(n, vector<char>(m));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res[j][m - 1 - i] = mat[i][j];
            }
        }
        return res;
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();

        for(auto &v : box){
            int stones = 0;
            int l = 0;

            for(int i = 0; i < n; i++){
                if(v[i] == '#'){
                    stones++;
                }
                else if(v[i] == '*'){
                    for(int j = i - 1; j >= l; j--){
                        if(stones > 0){
                            v[j] = '#';
                            stones--;
                        } else {
                            v[j] = '.';
                        }
                    }
                    l = i + 1;
                    stones = 0;
                }
            }

            for(int j = n - 1; j >= l; j--){
                if(stones > 0){
                    v[j] = '#';
                    stones--;
                } else {
                    v[j] = '.';
                }
            }
        }

        return rotate90Clockwise(box);
    }
};