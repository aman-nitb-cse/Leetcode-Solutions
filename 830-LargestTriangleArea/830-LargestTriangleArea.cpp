// Last updated: 6/25/2026, 11:20:53 PM
class Solution {
public:
    int sq(int x){
        return x * x;
    }
    double area(vector <int> v1, vector <int> v2, vector <int> v3){
        return 0.5 * abs((v1[0] * (v2[1] - v3[1]) + v2[0] * (v3[1] - v1[1]) + v3[0] * (v1[1] - v2[1])));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxi = 0;
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                for(int k = j + 1; k < points.size(); k++){
                    double A = area(points[i], points[j], points[k]);
                    maxi = max(maxi, A);
                }
            }
        }
        return maxi;
    }
};