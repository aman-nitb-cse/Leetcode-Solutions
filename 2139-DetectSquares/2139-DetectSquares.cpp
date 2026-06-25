// Last updated: 6/25/2026, 11:13:36 PM
class DetectSquares {
public:
    int v[1001][1001] = {0}; // v[x][y] = count of point (x, y)
    void add(vector<int> point) {
        v[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int ans = 0;

        for(int k = - x; x + k < 1001; k++){
            if(k == 0 || v[x + k][y] == 0) continue;
            if(y + k < 1001 && y + k >= 0) ans += v[x + k][y] * v[x + k][y + k] * v[x][y + k];
            if(y - k >= 0 && y - k < 1001) ans += v[x + k][y] * v[x + k][y - k] * v[x][y - k];
        }
        return ans;
    }
};