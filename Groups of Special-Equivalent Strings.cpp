// Question Link ---> https://leetcode.com/problems/groups-of-special-equivalent-strings/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        string even = "";
		string odd = "";
        unordered_set<string> s;
        for(auto str : A) {
        	for(int i=0; i<str.size(); i++) {
        		if(i%2 == 0) {
        			even += str[i];
				}
				else {
        			odd += str[i];
				}
			}
			sort(even.begin(), even.end());
			sort(odd.begin(), odd.end());
			s.insert(even+odd);
			even.clear();
			odd.clear();
		}
        return s.size();
    }
};

int main(void) {
	vector<string> A = {"abcd","cdab","adcb","cbad"};
	Solution obj;
	cout << obj.numSpecialEquivGroups(A) << endl;
	return 0;
}
