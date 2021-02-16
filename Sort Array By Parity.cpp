//QUESTION Link ---> https://leetcode.com/problems/sort-array-by-parity/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	    vector<int> sortArrayByParity(vector<int> &A) {
			vector<int> even;
			vector<int> odd;
			for(int i=0; i<A.size(); i++) {
				cout << A[i];
				if(A[i]%2 == 0) { // If it is EVEN
					even.push_back(A[i]);
					//ordered.insert(ordered.begin(), A[i]);
				}		
				else { // If it is ODD
					odd.push_back(A[i]); // 3, 5, 7
				}
			}
			
			for(int i=0; i<odd.size(); i++) {
				even.push_back(odd[i]);
			}
			
			//even.insert(even.end(), odd.begin(), odd.end());
			return even;
	    }
};

int main(void) {
	Solution obj;
	vector<int> vec = {3,1,2,4};
	vector<int> answer;
	
	answer = obj.sortArrayByParity(vec);
	cout << endl << endl;
	for(int i=0; i<answer.size(); i++) {
		cout << answer[i];
	}
	return 0;
}
