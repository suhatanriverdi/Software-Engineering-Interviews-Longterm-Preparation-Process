//QUESTION Link ---> https://leetcode.com/problems/all-paths-from-source-to-target/
#include <iostream>
#include <vector>
using namespace std;

class Solution {	
	public:
		vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
			vector<vector<int>> res;
			vector<int> temp;
			dfs(graph, res, 0, temp);
			return res;
		}
	
	    void dfs(const vector<vector<int>>& graph, vector<vector<int>> &res, int pos, vector<int> temp) {
			temp.push_back(pos);
			if(pos == graph.size()-1) {
				res.push_back(temp);
			}			
			else {
				for(int i=0; i<graph[pos].size(); i++) {
					dfs(graph, res, graph[pos][i], temp);
				}
			}
		}
};

int main(void) {
	vector<vector<int>> graph = {{1,2}, {3}, {3}, {}};
	vector<vector<int>> result;		
	Solution ans;
	result = ans.allPathsSourceTarget(graph);
	for (int i = 0; i<result.size(); i++) {
		for (int j = 0; j<result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
