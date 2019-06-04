//QUESTION Link ---> https://leetcode.com/problems/all-paths-from-source-to-target/
#include <iostream>
#include <vector>
using namespace std;

class Solution {	
	public:
	    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph, int dst) {
			vector<bool> isVisited(graph.size(), false); // Create bool vector with size of Graph
	    	vector<vector<int>> allPaths;
			vector<int> path;
	    	if(graph.size() == 0) {
				return allPaths;
			}
			helperDFS(isVisited, path, allPaths, graph, 0, dst);
			return allPaths;
	    }
				
	    void helperDFS(vector<bool> &isVisited, vector<int> path, vector<vector<int>> &allPaths, vector<vector<int>> &graph, int current, int last) {
	    	isVisited[current] = true; // Mark current child as visited
			path.push_back(current);
			if(current == last) {
				allPaths.push_back(path);
				isVisited[current] = false;
				return;
			}
			else {
				vector<int>::iterator it;
				for(it = graph[current].begin(); it != graph[current].end(); it++) {
					if(!isVisited[*it]) { // Check whether child is visited?
						helperDFS(isVisited, path, allPaths, graph, *it, last);
					}
				}
			}
			isVisited[current] = false;
		}
};

int main(void) {
	vector<vector<int>> graph = {{1}, {0,2,3}, {}, {2}};
	vector<vector<int>> result;
	int dst = 2; // We need to know destination and source! From 0 to 4 in this sample
	Solution ans; // Create Solution object
	result = ans.allPathsSourceTarget(graph, dst); // Send graph to Solution, Save answer into result vector
	for (int i = 0; i<result.size(); i++) { // Print Result
		for (int j = 0; j<result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
