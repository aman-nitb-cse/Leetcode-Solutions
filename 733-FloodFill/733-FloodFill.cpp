// Last updated: 6/25/2026, 11:36:51 PM
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int r, int c, int color) {
        if(img[r][c] == color) return img;
        int old = img[r][c];
        img[r][c] = color;

        if(r && img[r - 1][c] == old) floodFill(img, r - 1, c, color);
        if(c && img[r][c - 1] == old) floodFill(img, r, c - 1, color);
        if(r != img.size() - 1 && img[r + 1][c] == old) floodFill(img, r + 1, c, color);
        if(c != img[0].size() - 1 && img[r][c + 1] == old) floodFill(img, r, c + 1, color);
        return img;
    }
};