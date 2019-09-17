// Question Link ---> https://leetcode.com/problems/find-common-characters/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
		// We have at least 2 string
        vector<char> temp;
        vector<char> temp2;
		appendToVector(A[0], temp);
        for(int i=1; i<A.size(); i++) {
			appendToVector(A[i], temp2);
			vector<char> intersec;
			sort(temp.begin(),temp.end());
			sort(temp2.begin(),temp2.end());
			set_intersection(temp.begin(), temp.end(), temp2.begin(), temp2.end(), back_inserter(intersec));
			temp = intersec;
			temp2.clear();
//			for(auto c : temp) {
//				cout << c << " ";
//			} cout << endl;
		}
		A.clear();
		for(auto c : temp){
			string s(1, c);
			A.push_back(s);
		};
		return A;
    }
	
    void appendToVector(string &str, vector<char> &vec) {
    	for(auto c : str) {
    		vec.push_back(c);
		}
	}
};

int main(void) {
	vector<string> res;
	vector<string> A = {"bella","label","roller"};
	Solution obj;
	res = obj.commonChars(A);
	for(auto i : res) {
		cout << i << " ";
	}
	return 0;
}
