#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void iterativeDFS(vector<vector<int>> &graph) {
	vector<bool> isVisited(graph.size(), false); // Create bool vector with size of Graph
	stack<int> s; // Create stack
	isVisited[0] = true; // First node now marked as visited!
	s.push(0); // Push first element into Stack
	vector<int>::iterator it;
	cout << s.top()  << " ";	
	ret:
	while(!s.empty()) {
		int temp = s.top();
		for(it = graph[temp].begin(); it != graph[temp].end(); it++) { // Push each child of popped node into stack!
			if(!isVisited[*it]) { // Check whether child is visited?
				isVisited[*it] = true; // Mark current child as visited
				s.push(*it); // If child is now visited, push into stack
				temp = *it;
				cout << temp  << " ";	
				goto ret;
			}
		}
		s.pop(); // Pop the element
	}
}

int main(void) {
	vector<vector<int>> graph = {{1,2,5}, {3,4}, {3}, {4}, {}};
	iterativeDFS(graph);
	return 0;
}
