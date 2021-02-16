#include <iostream>
#include <vector>
using namespace std;

// Review of Recursive Function Call Stack
// The Function will be called 6 times (As much as Number of Nodes)
/*

Note That -> [x] is the current item.

______________->   Initial Call in Main   <-__________________________ Current Printed: 0

		   [0]		1	  2	   3	4	5
graph = {{1,2,5}, {3,4}, {3}, {4}, {}, {}};

		   	   [0]	  1	     2	    3	   4      5
isVisited = {[true], false, false, false, false, false};


______________->   1.Call   <-__________________________ Current Printed: 1

		    0			1	  2	   3	4	5
graph = {{ [1] ,2,5}, {3,4}, {3}, {4}, {}, {}};
		  
		   	   0	 [1]	 2	    3	   4      5
isVisited = {true, [true], false, false, false, false};


______________->   2.Call   <-__________________________ Current Printed: 3

		    0	 	[1]       2	   3	4	5
graph = {{1,2,5}, { [3] ,4}, {3}, {4}, {}, {}};
		  
		   	   0	 1		 2	  [3]   4      5
isVisited = {true, true, false, [true], false, false};


______________->   3.Call   <-__________________________ Current Printed: 4

		    0	 	1     2	     [3]    4	5
graph = {{1,2,5}, {3,4}, {3}, { [4] }, {}, {}};
		  
		   	   0	 1		2	  3      4      5
isVisited = {true, true, false, true, [true], false};


______________->   4.Call   <-__________________________ 4 has no child, Skip Forloop, Return [3]

		    0	 	1     2	   3     [4]	5
graph = {{1,2,5}, {3,4}, {3}, {4}, { [] }, {}};
		  
		   	   0	 1		2	  3      4      5
isVisited = {true, true, false, true, [true], false};


______________->   5.Call   <-__________________________ Current Printed: 2,  Return [1] and Return [0] then Call [2]

		     [0]	 	1     2	   3    4  	5
graph = {{1, [2] ,5}, {3,4}, {3}, {4}, {}, {}};     	// 3 in [2] is Already Visited! Enter For loop but quit from if!
		  												// Return [0] again
		   	   0	 1	   [2]	   3     4      5
isVisited = {true, true, [true], true, true, false}; 


______________->   6.Call   <-__________________________ Current Printed: 5

			[0]  	  1     2	 3    4   5
graph = {{1,2,[5]}, {3,4}, {3}, {4}, {}, {}};
		  
		   	   0	 1	   2	 3     4      5
isVisited = {true, true, true, true, true, [true]};

Finally, 5 has no child do no enter for loop and return [0]. And [0] has no child unvisited so finish the recursion. 
*/
		
void helperDFS(vector<vector<int>> &graph, int current, vector<bool> &isVisited) {
	for(int i=0; i<isVisited.size(); i++) {
		cout << "i: " << i << " isVisited: " << isVisited[i] << "\n";
	}
	cout << "---\n";
	cout << "Current: " << current << " \n";			
	vector<int>::iterator it;
	for(it = graph[current].begin(); it != graph[current].end(); it++) {
		if(!isVisited[*it]) { // Check whether child is visited?
			isVisited[*it] = true; // Mark current child as visited
			helperDFS(graph, *it, isVisited);
		}
	}
}

int main(void) {
	vector<vector<int>> graph = {{1,2,5}, {3,4}, {3}, {4}, {}, {}};
	vector<bool> isVisited(graph.size(), false);
	isVisited[0] = true; // First node now marked as visited!
	helperDFS(graph, 0, isVisited);
	return 0;
}
