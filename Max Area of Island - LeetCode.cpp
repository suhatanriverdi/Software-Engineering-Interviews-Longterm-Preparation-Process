//Question Link ---> https://leetcode.com/problems/max-area-of-island/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int maxAreaOfIsland(vector<vector<int>> &grid) {
			int maxArea = 0;
			int N = grid.size();
			int M = grid[0].size();
			vector<vector<bool>> isVisited(N, vector<bool>(M, false));
			for (int i = 0; i<N; i++) {
				for (int j = 0; j<M; j++) {
					if (grid[i][j] == 1 && !isVisited[i][j]) { // Search Around of 1's
						maxArea = max(findArea(i, j, grid, isVisited), maxArea);
					}
				}
			}
			return maxArea;
		}

		int findArea(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &isVisited) {
			if(x>=0 && x<grid.size() && y>=0 && y<grid[x].size() && grid[x][y] == 1 && isVisited[x][y] == false) {
				isVisited[x][y] = true;
				int area = 1;
				pair<int, int> directions[4] = {{x, y+1}, {x, y-1}, {x-1, y}, {x+1, y}}; // right-left-up-down
				for(int i = 0; i<4; i++) {
					int nx = directions[i].first;	
					int ny = directions[i].second;
					// int childArea...
					area += findArea(nx, ny, grid, isVisited);
				}
				return area;
			}
			return 0;
		}
};

int main(void) {
//	vector<vector<int>> grid = {
////		  	   0 1 2 3 4
//		/*0*/{ 1,1,1,1,1 },
//		/*1*/{ 0,0,0,1,0 },
//		/*2*/{ 0,0,0,1,0 },
//		/*3*/{ 0,0,0,1,0 }
//	};
	vector<vector<int>> grid = {
	{ 0,0,1,0,0,0,0,1,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,1,0,0,0 },
	{ 0,1,1,0,1,0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,1,1,0,0,1,0,1,0,0 },
	{ 0,1,0,0,1,1,0,0,1,1,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,1,1,1,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,0,0,0,0 }
	};

	
	Solution obj;
	cout << "Max area of island is: " << obj.maxAreaOfIsland(grid);
	return 0;
}
