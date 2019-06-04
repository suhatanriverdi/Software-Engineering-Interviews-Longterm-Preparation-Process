#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void iterativeDFS(vector<vector<int>> &graph) {
	vector<bool> isVisited(graph.size(), false); // Create bool vector with size of Graph
	stack<int> s; // Create stack
	vector<int> lastProcessedChild(graph.size());
	isVisited[0] = true; // First node now marked as visited!
	s.push(0); // Push first element into Stack
	lastProcessedChild.push_back(0);
	vector<int>::iterator it;
	cout << "Node -> " << s.top()  << " ";	
	while(!s.empty()) {
		bool noBreak = true;
		bool executed = false;
		int temp = s.top();
		it = graph[temp].begin()+lastProcessedChild[temp]; // To tell iterator which node's beginning
	 	//advance(it, lastProcessedChild[temp]); // Increment Iterator
		for(/*Below line is Used for loop start*/; !executed && it != graph[temp].end(); it++) { // Push each child of popped node into stack!
			if(!isVisited[*it]) { // Check whether child is visited?
				isVisited[*it] = true; // Mark current child as visited
				s.push(*it); // If child is now visited, push into stack
				lastProcessedChild[temp] += 1; // Save the last Processed child
				cout << "LastProcessedChild of " << temp << " is " << lastProcessedChild[temp];
				cout << endl;
				temp = *it;
				cout << "Node -> " << temp  << " ";	
				noBreak = false;
				executed = true;
			}
		}
		if(noBreak) {
			s.pop(); // Pop the element
		}
	}
}

int main(void) {
	vector<vector<int>> graph = {{1,2,5}, {3,4}, {3}, {4}, {}, {}};
	iterativeDFS(graph);
	return 0;
}
