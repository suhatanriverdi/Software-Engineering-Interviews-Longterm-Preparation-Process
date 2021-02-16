// Breadth First Search (BFS). It will work on both Directed and Undirected Graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
	private:
		vector<vector<int>> graph;
		int size;
		
	public:
		Graph(const vector<vector<int>> &graph, const int &sz):size(sz), graph(graph){};	
		void printGraph(vector<vector<int>> &graph) {
			for (int i = 0; i<graph.size(); i++) {
				for (int j = 0; j<graph[i].size(); j ++) {
					cout << graph[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		
		void bfs(int head) {
			vector<bool> isVisited(size, false);
			queue<int> queue;	
			isVisited[head] = true;
			queue.push(head);			 		
			while(!queue.empty()) {
				head = queue.front();
				cout << head << " ";
				queue.pop();	
				for(vector<int>::iterator it = graph[head].begin(); it != graph[head].end(); ++it) {
					if(!isVisited[*it]) {
						isVisited[*it] = true;
						queue.push(*it);
					}
				}
			}
		}
};

int main(void) {
	//Directed Graph
	vector<vector<int>> Directed = {{1,2}, {3}, {3}, {}};
	//Undirected Graph
	vector<vector<int>> Undirected = {{5,3}, {5,2,4}, {1,4}, {0,5}, {1,2}, {0,1,3}};
	Graph graph(Undirected, 6); // We need size!
	graph.printGraph(Undirected);
	graph.bfs(0);
	return 0;
}
