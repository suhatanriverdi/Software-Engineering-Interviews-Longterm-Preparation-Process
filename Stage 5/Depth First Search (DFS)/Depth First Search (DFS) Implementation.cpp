// Depth First Search (DFS). It will work on both Directed and Undirected Graph
#include <iostream>
#include <vector>
#include <stack>
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
		
		void dfs(int head) {
			vector<bool> isVisited(size, false);
			stack<int> stack;	
			isVisited[head] = true;
			stack.push(head); //We actually push node 0, not the number itself			
			vector<int>::iterator it; 		
			while(!stack.empty()) {
				head = stack.top();
				cout << head << " ";
				stack.pop();	
				for(it = graph[head].begin(); it != graph[head].end(); it++) {
					if(!isVisited[*it]) {
						isVisited[*it] = true;
						stack.push(*it);
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
	graph.dfs(0);
	return 0;
}
