//Question Link ---> https://leetcode.com/problems/island-perimeter/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	    int islandPerimeter(vector<vector<int>>& grid) {
	        int sum = 0;
			int N = grid.size();
			int M = grid[0].size();
			for (int i = 0; i<N; i++) {
				for (int j = 0; j<M; j++) {
					if(grid[i][j] == 1) { // Search Around of 1's
						sum += findPerimeter(i, j, grid);
					}
				}
			}
			return sum;
	    }
	    
	    int findPerimeter(int x, int y, vector<vector<int>> &grid) {
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
};

int main(void) {
	vector<vector<int>> grid = {
//		  	   0 1 2 3 4
		/*0*/{ 0,1,0,0 },
		/*1*/{ 1,1,1,0 },
		/*2*/{ 0,1,0,0 },
		/*3*/{ 1,1,0,0 }
	};

	Solution obj;
	cout << "Island Perimeter is: " << obj.islandPerimeter(grid);
	return 0;
}
