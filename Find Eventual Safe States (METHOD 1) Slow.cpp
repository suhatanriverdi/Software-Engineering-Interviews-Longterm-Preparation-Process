// Question Link ---> https://leetcode.com/problems/find-eventual-safe-states/
// Return Eventually Safe Nodes as an array in sorted order.
#include <iostream>
#include <vector>
#include <stack>
#include <set> // We Need Sorted Set!
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        vector<int> safesStates;
        set<int> unsafes;
        set<int> temporarySafeNodes;
        
        //First Pass -> finds Nodes within the loop
        for(int i = 0; i<graph.size(); i++) { // For Each Node
        	if(!unsafes.count(i) && isNodeWithinLoop(graph, i)) {
        		unsafes.insert(i);
			}
			else {
				temporarySafeNodes.insert(i);
			}
		}
		
		cout << "Unsafes Nodes so far: ";
		set<int>:: iterator its;
		for(its = unsafes.begin(); its != unsafes.end(); its++) {
			cout << *its << " ";
		}
		cout << endl << endl;
		
		cout << "Temporary Safes Nodes so far: ";
		set<int>:: iterator tmp;
		for(tmp = temporarySafeNodes.begin(); tmp != temporarySafeNodes.end(); tmp++) {
			cout << *tmp << " ";
		}
		cout << endl << endl;
		
		// Second Pass -> finds Nodes that is not in the loop but has a connection
		set<int>:: iterator ts;
		for(ts = temporarySafeNodes.begin(); ts != temporarySafeNodes.end(); ts++) {
			if(doesNodeTouchUnsafes(graph, unsafes, *ts)) {
				unsafes.insert(*ts);
			}
			else {
				safesStates.push_back(*ts);
			}
		}
        
        return safesStates;
    }
    
    bool isNodeWithinLoop(vector<vector<int>> &graph, int srcNode) {
		vector<bool> isVisited(graph.size(), false);	
		stack<int> s;
		s.push(srcNode);
		isVisited[srcNode] = true;
    	while(!s.empty()) {
    		int current = s.top();
    		s.pop();
    		cout << current << " " << endl;
    		vector<int>::iterator it;
	        for(it = graph[current].begin(); it != graph[current].end(); it++) {
	        	if(srcNode == *it) {
	        		cout << "Cycle Found!: " << *it << " is in the Loop!" << endl;
	        		return true;
				}
	        	if(!isVisited[*it]) {
	        		s.push(*it);
	        		isVisited[current] = true;
				}
			}
		}
		return false;
	}
	
	bool doesNodeTouchUnsafes(vector<vector<int>> &graph, set<int> &unsafes, int srcNode) {
		vector<bool> isVisited(graph.size(), false);	
		stack<int> s;
		s.push(srcNode);
		isVisited[srcNode] = true;
    	while(!s.empty()) {
    		int current = s.top();
    		s.pop();
    		cout << current << " " << endl;
    		if(unsafes.count(current)) {
    			cout << "Unsafe Node Found, we touched the cycle!: " << current << endl;
    			return true;
			}
    		vector<int>::iterator it;
	        for(it = graph[current].begin(); it != graph[current].end(); it++) {
//	        	if(unsafes.count(*it)) { // During DFS, if we reach any unsafe node, we are also unsafe!
//	        		cout << "Unsafe Node Found, we touched the cycle!: " << *it << endl;
//	        		return true;
//				}
	        	if(!isVisited[*it]) {
	        		s.push(*it);
	        		isVisited[current] = true;
				}
			}
		}
		return false;
	}
};

int main(void) {
								   //0     1    2   3   4   5  6 ---> Nodes	
//	vector<vector<int>> vec = {{1,2},{2,3},{5},{0},{5},{},{}}; // ---> Edges
	
							 //0      1      2      3   4 ---> Nodes	
	vector<vector<int>> vec = {{0},{2,3,4},{3,4},{0,4},{}}; // ---> Edges

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
