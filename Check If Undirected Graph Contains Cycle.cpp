// Question Link ---> https://www.techiedelight.com/check-undirected-graph-contains-cycle-not/
// if there is an adjacent ‘u’ such that u is already visited and u is not parent of v
// then there is a cycle in graph
#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Solution {
public:
	bool hasCycle(vector<vector<int>> &graph, int start) {
		int N = graph.size();
		vector<bool> isVisited(N, false);
		queue<pair<int, int>> q;
		q.push({ start, -1 });
		isVisited[start] = true;
		while (!q.empty()) {
			pair<int, int> temp = q.front();
			int current = temp.first;
			int parent = temp.second;
			q.pop();
			cout << "Visited: " << current + 1 << endl;
			for (int child = 0; child<N; child++) {
				if (graph[current][child] && !isVisited[child]) { // If 1 is found means it is neighbour
					q.push(child, current);
					isVisited[child] = true;
				}
				if (graph[current][child] && isVisited[child] && child != parent) {
					return true;
				}
			}
		}
		return false;
	}
};

int main(void) {
	//ADJACENCY MATRIX REPRESENTATION
	vector<vector<int>> undirected_graph = {
		//1 2 3 4 5
		/*1*/{ 0,0,0,1,0 },
		/*2*/{ 0,0,0,0,0 },
		/*3*/{ 0,0,0,0,0 },
		/*4*/{ 1,0,0,0,0 },
		/*5*/{ 0,0,0,0,0 },
	};

	//	vector<vector<int>> undirected_graph = {
	//	    //1 2 3 4 5
	//	/*1*/{0,0,0,1,0},
	//	/*2*/{0,0,0,1,1},
	//	/*3*/{0,0,0,0,1},
	//	/*4*/{1,1,0,0,1},
	//	/*5*/{0,1,1,1,0},
	//	};


	//	//ADJACENCY LIST REPRESENTATION
	//	//vector<list<int>> myVectorOfLists; // Or we can use vectors
	// 	list<int> undirectedGraph[5]; // index 0 will be used as 1
	// 	undirectedGraph[0].push_back(4);
	// 	
	// 	undirectedGraph[1].push_back(4);
	// 	undirectedGraph[1].push_back(5);
	// 	
	// 	undirectedGraph[2].push_back(5);
	// 	
	// 	undirectedGraph[3].push_back(1);
	// 	undirectedGraph[3].push_back(2);
	// 	undirectedGraph[3].push_back(5);
	// 	
	// 	undirectedGraph[4].push_back(2);
	// 	undirectedGraph[4].push_back(3);
	// 	undirectedGraph[4].push_back(4);

	Solution obj;
	cout << endl << obj.hasCycle(undirected_graph, 0);
	return 0;
}
