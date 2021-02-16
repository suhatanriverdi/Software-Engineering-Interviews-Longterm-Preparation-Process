//Question Link ---> https://www.techiedelight.com/chess-knight-problem-find-shortest-path-source-destination/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
	public:
		pair<int, int> knightDirections[8] = { // 8 Directions from any point
			{-2, +1},	{-2, -1},	{-1, +2},	{-1, -2},	{+1, -2},	{+1, +2},	{+2, +1},	{+2, -1}
		};
		int size = 0;
	    int shortestPath(int n, pair<int, int> src, pair<int, int> dst) {
	    	size = n;
	    	vector<pair<int, int>> path;
			vector<vector<int>> board(n, vector<int>(n, 0));
			int N = board.size();
			int M = board[0].size();
	    	vector<vector<int>> distance(N, vector<int>(M, 0));
	    	return knightSteps(board, src, dst, distance);
		}
		
	    int knightSteps(vector<vector<int>> &board, pair<int, int> &src, pair<int, int> &dst, vector<vector<int>> &distance) {
	    	int x = src.first;
	    	int y = src.second;
	    	queue<pair<int,int>> q;
	    	distance[x][y] = 1; // Mark Source as Visited and This 1 means First Step
			q.push(src);
			while(!q.empty()) {
				pair<int,int> temp = q.front();
				cout << "first: " << temp.first << " sec: " << temp.second << endl;
				x = temp.first;
	    		y = temp.second;	
				q.pop();
				for(int i=0; i<8; i++) {
					int nx = x + knightDirections[i].first;
					int ny = y + knightDirections[i].second;
					if(nx < size && nx >= 0 && ny < size && ny >= 0 && !distance[nx][ny]) {
						cout << "x: " << nx << " y: " << ny << endl;
						distance[nx][ny] = distance[x][y] + 1; // Two birds One Stone
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
};

int main(void) {
	Solution obj;
	cout << "Minimum number of steps required is: " << obj.shortestPath(8, {7,0}, {0,7});
	
// Alternative Testcases
//	cout << "Minimum number of steps required is: " << obj.shortestPath(1, {0,0}, {0,0});

//	cout << "Minimum number of steps required is: " << obj.shortestPath(-1, {0,0}, {0,0});

//	cout << "Minimum number of steps required is: " << obj.shortestPath(1, {9,9}, {9,9});

//	cout << "Minimum number of steps required is: " << obj.shortestPath(5, {0,0}, {0,0});

//	cout << "Minimum number of steps required is: " << obj.shortestPath(8, {0,7}, {7,0});

//	cout << "Minimum number of steps required is: " << obj.shortestPath(8, {0,7}, {0,7});

//	cout << "Minimum number of steps required is: " << obj.shortestPath(8, {7,7}, {7,7});

//	cout << "Minimum number of steps required is: " << obj.shortestPath(8, {7,7}, {6,7});

//	cout << "Minimum number of steps required is: " << obj.shortestPath(8, {0,0}, {0,1});

//	cout << "Minimum number of steps required is: " << obj.shortestPath(8, {0,0}, {1,0});

//	cout << "Minimum number of steps required is: " << obj.shortestPath(5, {4,0}, {0,4});
	return 0;
}
