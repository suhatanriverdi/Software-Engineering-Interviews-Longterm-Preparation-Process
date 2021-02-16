// Question Link ---> https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;	
		
class Solution {
	public:
	    int repeatedNTimes(vector<int>& A) {
	        unordered_set<int> set;
	        int prevSetSize = set.size();
	        for(int i=0; i<A.size(); i++) {
	        	prevSetSize = set.size();
	        	set.insert(A[i]);
	        	cout << "Prev size: " << prevSetSize << endl;
	        	cout << "Set size: " << set.size() << endl;
	        	if(set.size() == prevSetSize) {
	        		return A[i];
				}
			}
	    }
};

int main(void) {
	vector<int> vec = {1,2,3,3};
	Solution obj;
	cout << "Repeated element is: " << obj.repeatedNTimes(vec) << endl;
	return 0;
}
