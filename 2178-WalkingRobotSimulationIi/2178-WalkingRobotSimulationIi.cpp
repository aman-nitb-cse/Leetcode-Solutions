// Last updated: 6/25/2026, 11:13:23 PM
class Robot {
public:
    int x, y, n, i = 0;
    bool moved = false;
    Robot(int _x, int _y) : x(_x), y(_y) {
        n = 2 * (x + y - 2);
    }
    
    void step(int st) {
        moved = true;
        i += st;
        i %= n;
    }
    
    vector<int> getPos() {
        if(i < x) return {i, 0};
        else if(i <= x + y - 2) return {x - 1, i - x + 1};
        else if(i <= 2 * x + y - 3) return {2 * x + y - 3 - i, y - 1};
        else return {0, n - i};
    }
    
    string getDir() {
        if(i == 0 && moved) return "South";
        else if(i < x) return "East";
        else if(i <= x + y - 2) return "North";
        else if(i <= 2 * x + y - 3) return "West";
        else return "South";
    }
};