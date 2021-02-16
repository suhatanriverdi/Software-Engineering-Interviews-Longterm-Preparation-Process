//Question Link ---> https://www.techiedelight.com/count-the-number-of-islands/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	    int FindNumberOfIslands(vector<vector<int>> &grid) {
	    	int M = grid.size();
	    	int N = grid[0].size();
	    	int numberOfIslands = 0;
	    	vector<vector<bool>> isVisited(M, vector<bool>(N, false));
			for(int i=0; i<M; i++) {
				for(int j=0; j<N; j++) {
					if(grid[i][j] == 1 && isVisited[i][j] == false) {
						numberOfIslands++;
						islands(i, j, grid, isVisited);
					}
				}
			}
			return numberOfIslands;
		}
		
		void islands(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &isVisited) {
			if(x < grid.size() && x >= 0 && y < grid[x].size() && y >= 0 && grid[x][y] == 1 && isVisited[x][y] == false) {
				isVisited[x][y] = true;
				pair<int,int> directions[8] = {{-1, 0}, {+1, 0}, {0, +1}, {0, -1}, {-1, +1}, {-1, -1}, {+1, +1}, {+1, -1}};
				for(int i=0; i<8; i++) {
					int nx = x + directions[i].first;
					int ny = y + directions[i].second;
					islands(nx, ny, grid, isVisited);
				}
			}
			
			else {
				return;
			}
		}
};

int main(void) {
	Solution obj;
	
//==========> Default Test Case <==========
//	vector<vector<int>> grid = {
//		{ 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
//		{ 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
//		{ 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
//		{ 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
//		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
//		{ 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
//		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
//		{ 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
//		{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
//		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }
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

//	vector<vector<int>> grid = { // Empty element causes an error! in this testcase
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
//		{ 0,0,0,0 },
//		{ 0,1,0,1 },
//		{ 0,0,1,0 },
//		{ 0,1,0,1 }
//	};

//	vector<vector<int>> grid = {
//		{ 1,0,0,1 },
//		{ 0,0,0,0 },
//		{ 0,0,0,0 },
//		{ 1,0,0,1 }
//	};

//	vector<vector<int>> grid = {
//		{ 1,0,0,1 },
//		{ 0,1,1,0 },
//		{ 0,1,1,0 },
//		{ 1,0,0,1 }
//	};

//	vector<vector<int>> grid = {
//		{ 0,1,0,1 },
//		{ 1,0,1,0 },
//		{ 0,1,0,1 },
//		{ 1,0,1,0 }
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
//		{ -1,0,0,0 },
//		{ 0,-1,0,0 },
//		{ 0,0,-1,0 },
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

//	vector<vector<int>> grid = {
//		{ 0,0,0 },
//		{ 0,-1,0 },
//		{ 0,0,0 }
//	};
	
	cout << "Number of islands: " << obj.FindNumberOfIslands(grid);
	return 0;
}
