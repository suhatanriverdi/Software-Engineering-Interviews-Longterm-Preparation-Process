// Question Link ---> https://leetcode.com/problems/rotate-image/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	// First Pass
    	for(int i = 0; i<matrix.size(); i++) {
			for(int j = i + 1; j<matrix.size(); j++) {
				int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
				//swap(matrix[i][j], matrix[j][i]); // Neden Daha Yavaþ? Internal Olarak Fazladan Biþey Yapýyor Gibi
			}
		}
		
		cout << "After First Pass: " << endl;
		printVector(matrix);
		
		//Seconds Pass
		for(int i = 0; i<matrix.size(); i++) {
			reverse(matrix[i].begin(), matrix[i].end());
		}
    }
    
    void printVector(vector<vector<int>>& matrix) {
    	for(int i = 0; i<matrix.size(); i++) {
			for(int j = 0; j<matrix[0].size(); j++) {
				cout << "  " << matrix[i][j];
			}	
			cout << endl;
		}
		cout << endl;
	}
};

int main(void) {
	vector<vector<int>> res;
	vector<vector<int>> A = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25}
	};
//	vector<vector<int>> A = {
//		{1,2,3},
//		{4,5,6},
//		{7,8,9}
//	};
//	vector<vector<int>> A = {
//		{5,1,9,11},
//		{2,4,8,10},
//		{13,3,6,7},
//		{15,14,12,16}
//	};

	cout << "Before Rotation:" << endl;
	for(int i = 0; i<A.size(); i++) {
		for(int j = 0; j<A[0].size(); j++) {
			cout << " " << A[i][j];
		}	
		cout << endl;
	}
	Solution obj;
	obj.rotate(A);
	cout << "After Rotation:" << endl;
	for(int i = 0; i<A.size(); i++) {
		for(int j = 0; j<A[0].size(); j++) {
			cout << " " << A[i][j];
		}	
		cout << endl;
	}
	return 0;
}
