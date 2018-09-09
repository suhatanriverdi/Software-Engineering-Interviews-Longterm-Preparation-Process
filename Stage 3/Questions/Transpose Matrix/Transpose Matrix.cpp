#include <iostream>
#include <vector>
using namespace std;

class Solution {
	
	public:
		
	    vector<vector<int>> transpose(vector<vector<int>>& A) {
	    	
	    	if(A.empty()) {
	    		return vector<vector<int>>();	
			}
			
	        vector<vector<int>> T; // New 2D Matrix
	        T.resize(A[0].size());
	        
			for(int i=0; i<A.size(); i++) {
				
				for(int j=0; j<A[0].size(); j++) {
					
					T[j].push_back(A[i][j]);
				}
			}
					
			return T;
	    }
};

int main(void) {
	
	vector<vector<int>> A = {{1,2,3},
							 {4,5,6}};
	
	vector<vector<int>> T;
	
	for(int i=0; i<A.size(); i++) {
		for(int j=0; j<A[i].size(); j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	
	Solution obj;
	
	T = obj.transpose(A);
	
	cout << "Transposed Matrix: " << endl;
	for(int i=0; i<T.size(); i++) {
		for(int j=0; j<T[i].size(); j++) {
			cout << T[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
