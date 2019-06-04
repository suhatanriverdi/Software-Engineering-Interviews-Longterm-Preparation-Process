//Question Link ---> https://leetcode.com/problems/island-perimeter/
//Now, there are many islands, this time we need to find the area which have the largest perimeter!
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	    int islandPerimeter(vector<vector<int>>& grid) {
	        int sum = 0;
			int N = grid.size();
			int M = grid[0].size();
			vector<vector<bool>> isVisited(N, vector<bool>(M, false));
			for (int i = 0; i<N; i++) {
				for (int j = 0; j<M; j++) {
					if(grid[i][j] == 1) { // Search Around of 1's
						sum = max(walkerOn1s(i, j, grid, isVisited), sum);
						//walkerOn1s(i, j, grid, isVisited);
					}
				}
			}
			return sum;
	    }
	    
	    int findPerimeterOfAnIsland(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &isVisited) {
	    	int per = 0;
    		pair<int, int> directions[4] = {{x, y+1}, {x, y-1}, {x-1, y}, {x+1, y}}; // right-left-up-down
			for(int i = 0; i<4; i++) {
				int nx = directions[i].first;
				int ny = directions[i].second;
				if(nx<0 || nx>grid.size()-1 || ny<0 || ny>grid[nx].size()-1 || grid[nx][ny] == 0) {	// On Borders	
					per++;
				}
			}
	    	return per;	
		}
		
		int walkerOn1s(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &isVisited) {
			if(x>=0 && x<grid.size() && y>=0 && y<grid[x].size() && grid[x][y] == 1 && isVisited[x][y] == false) {
				isVisited[x][y] = true;
				cout << "x: " << x << " y: " << y << endl;
				
				int perimeter = 0;
				perimeter += findPerimeterOfAnIsland(x, y, grid, isVisited); // Find one 1's Perimeter only
				cout << "perimeter: " << perimeter <<  endl;
				
	    		pair<int, int> directions[4] = {{x, y+1}, {x, y-1}, {x-1, y}, {x+1, y}}; // right-left-up-down
				for(int i = 0; i<4; i++) {
					int nx = directions[i].first;
					int ny = directions[i].second;
					perimeter += walkerOn1s(nx, ny, grid, isVisited);
				}
				return perimeter;
			}
			return 0;
		}
};

int main(void) {
//==========> Default Test Case <==========
//	vector<vector<int>> grid = {
////		  	   0 1 2 3
//		/*0*/{ 0,1,0,1 },
//		/*1*/{ 0,1,0,0 },
//		/*2*/{ 0,0,0,0 },
//		/*3*/{ 1,1,1,0 }
//	};
	
	
//_-_-_-_-_-_-> Alternative Test Cases <-_-_-_-_-_-_-_

//	vector<vector<int>> grid = {
//	{}
//	};

//	vector<vector<int>> grid = {
//	{},
//	{},
//	{}
//	};

//	vector<vector<int>> grid = {
//	{1},
//	{},
//	{}
//	};

//	vector<vector<int>> grid = { // Empty point causes error! in this testcase
//	{0},
//	{1},
//	{}
//	};

//	vector<vector<int>> grid = {
//		{ -1,0,-1 },
//		{ 0,-1,0 },
//		{ -1,0,-1 }
//	};

//	vector<vector<int>> grid = {
//		{ -1,-1,-1 },
//		{ -1,-1,-1 },
//		{ -1,-1,-1 }
//	};

//	vector<vector<int>> grid = {
//		{ -1,-1,-1 },
//		{ -1,0,-1 },
//		{ -1,-1,-1 }
//	};

//	vector<vector<int>> grid = {
//		{ -1,-1,-1 },
//		{ -1,1,-1 },
//		{ -1,-1,-1 }
//	};

//	vector<vector<int>> grid = {
//		{ 0,0,0,0 },
//		{ 0,0,0,0 },
//		{ 0,0,0,0 },
//		{ 0,0,0,0 }
//	};

//	vector<vector<int>> grid = {
//		{ 1,1,1,1 },
//		{ 1,1,1,1 },
//		{ 1,1,1,1 },
//		{ 1,1,1,1 }
//	};

//	vector<vector<int>> grid = {
//		{ 1,0,0,0 },
//		{ 0,1,0,0 },
//		{ 0,0,1,0 },
//		{ 0,0,0,1 }
//	};

//	vector<vector<int>> grid = {
//		{ 0,0,0,1 },
//		{ 0,0,1,1 },
//		{ 0,1,0,1 },
//		{ 1,1,1,1 }
//	};

//	vector<vector<int>> grid = {
//		{ 1,0,1 },
//		{ 0,1,0 },
//		{ 1,0,1 }
//	};

//	vector<vector<int>> grid = {
//		{ -1,0,-1 },
//		{ 0,-1,0 },
//		{ 1,0,-1 }
//	};

//	vector<vector<int>> grid = {
//		{ 1,0,0 },
//		{ 0,1,0 },
//		{ 0,0,1 }
//	};

//	vector<vector<int>> grid = {
//		{ 0,0,1 },
//		{ 0,1,0 },
//		{ 1,0,0 }
//	};

//	vector<vector<int>> grid = {
//		{ 0,0,0 },
//		{ 1,1,1 },
//		{ 0,0,0 }
//	};

//	vector<vector<int>> grid = {
//		{ 1,0,0 },
//		{ 1,1,1 },
//		{ 0,0,1 }
//	};

//	vector<vector<int>> grid = {
//		{ 1,1,1 },
//		{ 1,0,1 },
//		{ 1,1,1 }
//	};

//	vector<vector<int>> grid = {
//		{ 1,0,0,1 },
//		{ 0,0,0,0 },
//		{ 0,0,0,0 },
//		{ 1,0,0,1 }
//	};

//	vector<vector<int>> grid = {
//		{ 0,1,1,1 },
//		{ 1,0,0,1 },
//		{ 1,0,0,1 },
//		{ 1,1,1,1 }
//	};

//	vector<vector<int>> grid = {
//		{ 1,1,1,1 },
//		{ 1,0,0,1 },
//		{ 1,0,0,1 },
//		{ 1,1,1,1 }
//	};

//	vector<vector<int>> grid = {
//		{ 0,1,1,0 },
//		{ 1,0,0,1 },
//		{ 1,0,0,1 },
//		{ 0,1,1,0 }
//	};

//	vector<vector<int>> grid = {
//		{ 0,0,0 },
//		{ 0,1,0 },
//		{ 0,0,0 }
//	};

	Solution obj;
	cout << "Island Perimeter is: " << obj.islandPerimeter(grid);
	return 0;
}
