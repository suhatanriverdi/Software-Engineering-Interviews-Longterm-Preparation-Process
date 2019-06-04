// Question Link ---> https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for(int i = 0 ; i<grid.size(); i++) {
            for(int j = 0 ; j<grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    walkOnIsland(i, j, grid);
                    num++;
                }
            }   
        }
        return num;
    }
    void walkOnIsland(int x, int y, vector<vector<char>> &grid) {
        pair<int, int> directions[4] = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};
        for(int i = 0 ; i<4; i++) {
            int nx = directions[i].first;
            int ny = directions[i].second;
            if(nx<grid.size() && nx>=0 && ny<grid[nx].size() && ny>=0 && grid[nx][ny] == '1') {
                grid[nx][ny] = '0';
                walkOnIsland(nx, ny, grid);
            }
        }
    }
};