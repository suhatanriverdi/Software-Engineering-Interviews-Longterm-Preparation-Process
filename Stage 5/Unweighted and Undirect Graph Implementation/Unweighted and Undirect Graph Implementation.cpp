//Implementing of Unweighted and Undirected Graph, Adjacency Matrix, Using 2D Vectors
//Undirected means that TWO-WAY direction from node to node
//Directed means that ONLY ONE WAY direction from node to node (Either GOING or RETURN)
#include <iostream>
#include <utility> // std::pair
#include <vector>
using namespace std;
//3x2 sample vector{ { 1, 2 },
// 	 		         { 3, 4 },
//  	 		     { 5, 6 } };
//vec.size() => 3
//vec[0].size() => 2
// i -> Row
// j -> Column

class Graph {
	private:
		vector< vector<int> > graph;
		vector<pair<int, int>> vectorOfPair;
		
	public:
		void addVertex(const int &value) {
			graph.push_back(vector<int> {value});
		}
		
		void savePair(const int &first, const int &second) {
			vectorOfPair.push_back(make_pair(first, second));
		}
		
		void printVectorOfPair() {
		    for(int i = 0; i < vectorOfPair.size(); i++) {
				cout << vectorOfPair[i].first << ", " << vectorOfPair[i].second << endl; 
		    }
		}
		
		bool checkIfContains(const int &first, const int &second) {
			if (first == second) {
				cout << "Invalid process! -> " << first << " is equal to " << second << endl;
				return false;
			}
			
			if (vectorOfPair.size() == 0) {
				vectorOfPair.push_back(make_pair(first, second));
				return true;
			}
			
			pair<int, int> tempPair;
			pair<int, int> swapped;
			tempPair = make_pair(first, second);
			swapped.first = tempPair.second;
			swapped.second = tempPair.first;
			
			for (int i = 0; i < vectorOfPair.size(); i++) {
				if (vectorOfPair[i] == tempPair || vectorOfPair[i] == swapped) {
					cout << "This connection is already exist! -> " << first << ", " << second << endl;
					return false;
				}
			}
			vectorOfPair.push_back(make_pair(first, second));
			return true;
		}
		
		void addEdge(const int &from, const int &to) {
			if(checkIfContains(from, to)) {				
				for(int i = 0; i < graph.size(); i++) {
					if(graph[i][0] == from) {
					    for(int j = 0; j < graph.size(); j++) {
					    	if(graph[j][0] == to) {	
								graph.at(i).push_back(to);
								graph.at(j).push_back(from);
					    		break;
							}
					    }
				    }
				}
			}

			else {
				return;
			}		  
		}
		
		void printGraph() {
			for(int i=0; i<graph.size(); i++) {
				for(int j=0; j<graph[i].size(); j++) {
					if(j != 0) cout << " -> ";
					cout << graph[i][j];
				}
				cout << endl;
			}
		}
};

int main(void) {
	Graph graph;
	graph.addVertex(1);
	graph.addVertex(2);
	graph.addVertex(3);
	graph.addVertex(4);
	graph.addVertex(5);
	graph.addVertex(6);
	graph.addEdge(1, 2);
	graph.addEdge(1, 3);
	graph.addEdge(6, 5);
	graph.addEdge(1, 1);
	graph.addEdge(6, 5);
	graph.addEdge(2, 1);
	graph.printGraph();
	//graph.printVectorOfPair();
	return 0;
}
