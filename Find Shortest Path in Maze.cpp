//Question Link ---> https://www.techiedelight.com/find-shortest-path-in-maze/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
	pair<int, int> directions[4] = {{0, +1}, {0, -1}, {-1, 0}, {+1, 0}}; // right-left-up-down
	public:
	    int findShortestPath(vector<vector<int>> &grid, pair<int,int> src, pair<int,int> dst) {
	    	int M = grid.size();
	    	int N = grid[0].size();
	    	vector<vector<int>> distance(M, vector<int>(N, 0));
	    //	vector<vector<bool>> isVisited(M, vector<bool>(N, false));
			return walkerBFS(src, grid, distance, dst);
		}
		
		int walkerBFS(pair<int,int> &src, vector<vector<int>> &grid, vector<vector<int>> &distance, pair<int,int> &dst) {
			int x = src.first;
	    	int y = src.second;
	    	queue<pair<int,int>> q;
	    	distance[x][y] = 1; // Mark Source as Visited, This "1" means First Point
			q.push(src);
			while(!q.empty()) {
				pair<int,int> temp = q.front();
				q.pop();
				cout << "first: " << temp.first << " sec: " << temp.second << endl;
				x = temp.first;
	    		y = temp.second;	
				for(int i=0; i<4; i++) {
					pair<int, int> directions[4] = {{0, +1}, {0, -1}, {-1, 0}, {+1, 0}}; // right-left-up-down
					int nx = x + directions[i].first;
					int ny = y + directions[i].second;
					if(nx < grid.size() && nx >= 0 && ny < grid.size() && ny >= 0 && grid[nx][ny] && !distance[nx][ny]) {
						cout << "nx: " << nx << " ny: " << ny << endl;
						distance[nx][ny] = distance[x][y] + 1; // Two birds One Stone
						printDistance(distance);
						cout << "Distance Vector: " << distance[nx][ny] << endl;
						q.push({nx, ny});
					}
					
					if(nx == dst.first && ny == dst.second) {
						cout << "DESTINATION FOUND! " << "x: " << nx << " y: " << ny << endl;
						cout << "Distance: " << distance[nx][ny]-1 << endl;
						return (distance[nx][ny]-1);
					}
				}
			}
		}
		
		void printDistance(vector<vector<int>> &distance) {
			for(int i=0; i<distance.size(); i++) {
				for(int j=0; j<distance[i].size(); j++) {
					cout << distance[i][j] << " ";
				}
				cout << endl;
			}
		}
};

int main(void) {
	Solution obj;	
//==========> Default Test Case <==========
//	vector<vector<int>> maze = {
//		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
//		{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
//		{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
//		{ S, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
//		{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
//		{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
//		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
//		{ 0, D, 1, 1, 1, 1, 1, 1, 0, 0 },
//		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
//		{ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(maze, {0, 0}, {9, 9});

	
//_-_-_-_-_-_-> Alternative Test Cases <-_-_-_-_-_-_-_

//	vector<vector<int>> maze = {
//		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
//		{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
//		{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
//		{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
//		{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
//		{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
//		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
//		{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
//		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
//		{ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(maze, {0, 0}, {10, 10});


//	vector<vector<int>> maze2 = {
//		{1,0,0},
//		{0,0,0},
//		{0,0,0}
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {0, 0});

//	vector<vector<int>> maze = { // 
//		{-1,0,0},
//		{0,0,0},
//		{0,0,1}
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {2, 2});

//	vector<vector<int>> maze = { // 
//		{-1,1,0},
//		{0,1,0},
//		{0,1,1}
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {2, 2});

//	vector<vector<int>> maze = { // 
//		{1,1,0},
//		{0,1,0},
//		{0,1,0}
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {2, 2});

//	vector<vector<int>> grid = {
//	{}
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {0, 0});

//	vector<vector<int>> grid = {
//	{1},
//	{},
//	{}
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {0, 0});

//	vector<vector<int>> grid = { // Empty element causes an error! in this testcase
//	{0},
//	{1},
//	{}
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {0, 0});

//	vector<vector<int>> grid = {
//		{ -1,0,-1 },
//		{ 0,-1,0 },
//		{ -1,0,-1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {0, 0});

//	vector<vector<int>> grid = {
//		{ -1,-1,-1 },
//		{ -1,-1,-1 },
//		{ -1,-1,-1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {2, 2});

//	vector<vector<int>> grid = {
//		{ -1,-1,-1 },
//		{ -1,0,-1 },
//		{ -1,-1,-1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {2, 2});


//	vector<vector<int>> grid = {
//		{ -1,-1,-1 },
//		{ -1,1,-1 },
//		{ -1,-1,-1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {2, 2});


//	vector<vector<int>> grid = {
//		{ 0,0,0,0 },
//		{ 0,0,0,0 },
//		{ 0,0,0,0 },
//		{ 0,0,0,0 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {2, 2});

//	vector<vector<int>> grid = {
//		{ 0,0,0,0 },
//		{ 0,0,0,0 },
//		{ 0,0,0,0 },
//		{ 0,0,0,0 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {0, 0});


//	vector<vector<int>> grid = {
//		{ 1,0,0,0 },
//		{ 0,1,0,1 },
//		{ 0,0,1,0 },
//		{ 0,1,0,1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {3, 3});

//	vector<vector<int>> grid = {
//		{ 1,0,0,1 },
//		{ 0,0,0,0 },
//		{ 0,0,0,0 },
//		{ 1,0,0,1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {3, 3});

//	vector<vector<int>> grid = {
//		{ 1,0,0,1 },
//		{ 0,1,1,0 },
//		{ 0,1,1,0 },
//		{ 1,0,0,1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {3, 3});

//	vector<vector<int>> grid = {
//		{ 0,1,0,1 },
//		{ 1,0,1,0 },
//		{ 0,1,0,1 },
//		{ 1,0,1,0 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {3, 3});


//	vector<vector<int>> grid = {
//		{ 1,1,1,1 },
//		{ 1,1,1,1 },
//		{ 1,1,1,1 },
//		{ 1,1,1,1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {3, 3});


//	vector<vector<int>> grid = {
//		{ 1,0,0,0 },
//		{ 0,1,0,0 },
//		{ 0,0,1,0 },
//		{ 0,0,0,1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {3, 3});


//	vector<vector<int>> grid = {
//		{ -1,0,0,0 },
//		{ 0,-1,0,0 },
//		{ 0,0,-1,0 },
//		{ 0,0,0,1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {3, 3});


//	vector<vector<int>> grid = {
//		{ 0,0,0,1 },
//		{ 0,0,1,1 },
//		{ 0,1,0,1 },
//		{ 1,1,1,1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 3}, {3, 3});


//	vector<vector<int>> grid = {
//		{ 1,0,1 },
//		{ 0,1,0 },
//		{ 1,0,1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {2, 2});


//	vector<vector<int>> grid = {
//		{ -1,0,-1 },
//		{ 0,-1,0 },
//		{ 1,0,-1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {2, 2});


//	vector<vector<int>> grid = {
//		{ 1,0,0 },
//		{ 0,1,0 },
//		{ 0,0,1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {2, 2});

//	vector<vector<int>> grid = {
//		{ 0,0,0 },
//		{ 1,1,1 },
//		{ 0,0,0 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {1, 0}, {1, 2});


//	vector<vector<int>> grid = {
//		{ 1,0,0 },
//		{ 1,1,1 },
//		{ 0,0,1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {2, 2});


//	vector<vector<int>> grid = {
//		{ 1,1,1 },
//		{ 1,0,1 },
//		{ 1,1,1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {2, 2});


//	vector<vector<int>> grid = {
//		{ 1,0,0,1 },
//		{ 0,0,0,0 },
//		{ 0,0,0,0 },
//		{ 1,0,0,1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {3, 3});


//	vector<vector<int>> grid = {
//		{ 0,1,1,1 },
//		{ 1,0,0,1 },
//		{ 1,0,0,1 },
//		{ 1,1,1,1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 1}, {3, 3});


//	vector<vector<int>> grid = {
//		{ 1,1,1,1 },
//		{ 1,0,0,1 },
//		{ 1,0,0,1 },
//		{ 1,1,1,1 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 0}, {3, 3});


//	vector<vector<int>> grid = {
//		{ 0,1,1,0 },
//		{ 1,0,0,1 },
//		{ 1,0,0,1 },
//		{ 0,1,1,0 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {0, 1}, {3, 2});


//	vector<vector<int>> grid = {
//		{ 0,0,0 },
//		{ 0,1,0 },
//		{ 0,0,0 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {1, 1}, {1, 1});

//	vector<vector<int>> grid = {
//		{ 0,0,0 },
//		{ 0,-1,0 },
//		{ 0,0,0 }
//	};
//	cout << "Shortest Path: " << obj.findShortestPath(grid, {1, 1}, {1, 1});

	return 0;
}
