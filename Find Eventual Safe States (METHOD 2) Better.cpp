// Question Link ---> https://leetcode.com/problems/find-eventual-safe-states/
// Return Eventually Safe Nodes as an array in sorted order.
// Unsafe Node'a giden Nodelar kesinlikle Unsafe dir
// Safe Node'a giden Nodelara için kesin biþey söyleyemeyiz!!!
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;
using us = unordered_set<int>;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        us safes;
        us unsafes;
        us path;
        vector<int> safeStates;
		//vector<bool> isVisited(graph.size(), false);
		
        for(int i = 0; i<graph.size(); i++) { // Run DFS For Each Node
        	cout << "Node: " << i << "-_" << endl;
	    	//dfs(graph, unsafes, isVisited, path, i);
	    	if(dfs(graph, unsafes, safes, path, i)) {
	    		safeStates.push_back(i);
			}    	
		}
        
		cout << "Unsafes Nodes so far: ";
		us::iterator its;
		for(its = unsafes.begin(); its != unsafes.end(); its++) {
			cout << *its << " ";
		}
		cout << endl << endl;
		
		cout << "Safes Nodes so far: ";
		us::iterator tmp;
		for(tmp = safes.begin(); tmp != safes.end(); tmp++) {
			cout << *tmp << " ";
		}
		cout << endl << endl;    
        
        return safeStates;
    }
    
    bool dfs(vector<vector<int>> &graph, us &unsafes, us &safes, us path, int current) {
    	if(safes.count(current)) { // Already Safe
    		return true;
		}
		
		if(unsafes.count(current)) { // Already Unsafe
    		return false;
		}

		if(path.count(current)) { // During DFS, We detect CYCLE!
			cout << "Cycle Found: " << endl;
    		unsafes.insert(path.begin(),path.end()); // Mark all Nodes as Unsafe in a path!
    		return false;
		}
		
    	cout << current << " " << endl;
		path.insert(current);
		for(vector<int>::iterator it = graph[current].begin(); it != graph[current].end(); it++) {
			if(!dfs(graph, unsafes, safes, path, *it)) {
				return false;
			}
		}
	
		safes.insert(current);
		return true;
	}
};

int main(void) {
							   //0     1    2   3   4   5  6 ---> Nodes	
	vector<vector<int>> vec = {{1,2},{2,3},{5},{0},{5},{},{}}; // ---> Edges
	
							 //0      1      2      3   4 ---> Nodes	
//	vector<vector<int>> vec = {{0},{2,3,4},{3,4},{0,4},{}}; // ---> Edges

							//  0     1      2   3   4
//	vector<vector<int>> vec = {{},{0,2,3,4},{3},{4},{}}; // ---> Edges	
	vector<int> res;
	
	Solution obj;
	res = obj.eventualSafeNodes(vec);
	
	cout << endl << endl;
	cout << "Final Eventually Safe States: ";
	for(auto i:res) {
		cout << i << " ";
	}
	
	return 0;
}

//    void dfs(vector<vector<int>> &graph, set<int> &unsafes, vector<bool> isVisited, set<int> path, int current) {
//		cout << current << " " << endl;
//		isVisited[current] = true;
//		path.insert(current);
//		if(graph[current].size()) {
//			vector<int>::iterator it;
//			for(it = graph[current].begin(); it != graph[current].end(); it++) {
//				if(!isVisited[*it]) {
//					dfs(graph, unsafes, isVisited, path, *it);
//				}
//				else if(path.count(*it)) { // During DFS, If we go back to a point that is on our way
//	        		cout << "Unsafe Node Found: " << current << endl;
//	        		unsafes.insert(path.begin(),path.end()); // Mark all Nodes as Unsafe in a path!
//	        		return;
//				}
//			}
//		}
//		else {
//			cout << "Safe Node Found: " << current << endl;
//			return;
//		}
//	}

//	void findNodesInPath(vector<vector<int>> &graph, set<int> &unsafes, int srcNode) {
//		vector<bool> isVisited(graph.size(), false);	
//		set<int> path; // Temporary Set for A Func Call
//		stack<int> s;
//		s.push(srcNode);
//		path.insert(srcNode); // save the Node into Path
//		isVisited[srcNode] = true;
//    	while(!s.empty()) {
//    		int current = s.top();
//    		s.pop();
//    		cout << current << " " << endl;
//    		vector<int>::iterator it;
//	        for(it = graph[current].begin(); it != graph[current].end(); it++) {
//	        	if(!isVisited[*it] && !path.count(*it)) {
//	        		s.push(*it);
//	        		path.insert(*it);
//	        		isVisited[current] = true;
//				}
//	        	else if(path.count(*it)) { // During DFS, If we go back to a point that is on our way
//	        		cout << "Unsafe Node Found: " << srcNode << endl;
//	        		unsafes.insert(srcNode);
//				}
//			}
//		}
//	}
