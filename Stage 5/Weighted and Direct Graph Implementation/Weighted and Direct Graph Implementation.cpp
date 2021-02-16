//Implementing of Unweighted and Undirected Graph, Adjacency Matrix, Using 2D Vectors
//Undirected means that TWO-WAY direction from node to node
//Directed means that ONLY ONE WAY direction from node to node (Either GOING or RETURN)
#include <iostream>
#include <utility>      // std::pair
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
	
		void printVectorOfPair() {
			for (int i = 0; i < vectorOfPair.size(); i++) {
				cout << vectorOfPair[i].first << ", " << vectorOfPair[i].second << endl;
			}
			cout << endl << endl;
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
			
			for (int i = 0; i < vectorOfPair.size(); i++) {
				if (vectorOfPair[i] == tempPair) {
					cout << "This connection is already exist! -> " << first << ", " << second << endl;
					return false;
				}
			}
			vectorOfPair.push_back(make_pair(first, second));
			return true;
		}
	
		bool addEdge(const int &from, const int &to, const int &weight) {
			if (checkIfContains(from, to)) {
				for (int i = 0; i < graph.size(); i++) {
					if (graph[i][0] == from) {
						for (int j = 0; j < graph.size(); j++) {
							if (graph[j][0] == to) {
								graph.at(i).push_back(to);
								graph.at(i).push_back(weight);
								return true;
							}
						}
					}
				}
			}
			else {
				return false;
			}
		}
	
		void printGraph() {
			for (int i = 0; i<graph.size(); i++) {
				cout << "Source: " << i + 1 << endl;
				for (int j = 1; j<graph[i].size(); j += 2) {
					cout << " -> " << graph[i][j] << " with Weight(" << graph[i][j + 1] << ")";
					cout << endl;
				}
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
	//graph.addEdge(Source, Destination, Weight);
	graph.addEdge(1, 2, 32);
	graph.addEdge(1, 3, 55);
	graph.addEdge(1, 3, 89);
	graph.addEdge(3, 6, 723);
	graph.addEdge(3, 2, 123);
	graph.addEdge(2, 3, 13);
	graph.addEdge(5, 3, 145);
	graph.addEdge(6, 3, 167);
	graph.addEdge(6, 3, 11);
	graph.addEdge(1, 4, 100); // Will not be added to the Graph because 4 is non exist.
	graph.printGraph();
	//graph.printVectorOfPair();
	return 0;
}
