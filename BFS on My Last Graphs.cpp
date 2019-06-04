//Breadth First Search on 2D Vector Adjacency List Graphs
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//						     0       1       2     3     4   5   6
vector<vector<int>> graph = {{}, {3, 2, 4}, {}, {5, 6}, {}, {}, {}};

void bfs(int head) {
	cout << "graph size: " << graph.size() << endl;
	vector<bool> visited(graph.size(), false);
	queue<int> q;
	visited[head] = true;
	q.push(head);
	int temp;
	while(!q.empty()) {
		temp = q.front();
		cout << temp << " ";
		q.pop();
		for(vector<int>::iterator it = graph[temp].begin(); it != graph[temp].end(); it++) {
			if(!visited[*it]) {
				visited[*it] = true;
				q.push(*it);
			}
		}
	}
}

int main(void) {
	bfs(1); // Send root(first) element
	return 0;
}
