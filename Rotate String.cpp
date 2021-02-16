//Question Link ---> https://leetcode.com/problems/rotate-string/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size()) {
            return false;
        }
		
		if(A == B) {
			return true;
		}
			
		if((A+A).find(B) != string::npos) {
        	return true;
		}
		
		return false;
    }
};

int main(void) {
	string A = "bqqutquvbtgouklsayfvzewpnrbwfcdmwctusunasdbpbmhnvy";
	string B = "wpnrbwfcdmwctusunasdbpbmhnvybqqutquvbtgouklsayfvze";
	Solution obj;
	cout << obj.rotateString(A, B);
	return 0;
}
