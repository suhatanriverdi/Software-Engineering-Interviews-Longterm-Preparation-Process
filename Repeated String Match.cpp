//Question Link ---> https://leetcode.com/problems/repeated-string-match/
#include <iostream>
#include <vector>
#include <cstring> // For strlen();
using namespace std;

class Solution {
	public:
		int repeatedStringMatch(string A, string B) {
	        if(A.find(B) != string::npos) { // If A.size() >= B.size()
	        	return 1;
			}
	        
			string tempA = A;
			int count = 1;
			while(A.size() < B.size()) {
				A += tempA;
				count++;
				if(A.find(B) != string::npos) { // Check if B is substring of A?
					return count;
				}
			}
			A += tempA;
			if(A.find(B) != string::npos) {
				return count+1;
			}
			
			return -1;
	    }
		//AÞAÐIDAKÝ STRING OLAYLARINDA TIME LÝMÝT EXCEEDED HATASI VAR!?
//	    int repeatedStringMatch(string A, string B) {
//	        if(isSubstring(&A, &B)) { // If A.size() >= B.size()
//	        	return 1;
//			}
//	        
//			string tempA = A;
//			int count = 1;
//			while(A.size() < B.size()) {
//				cout << "A: " << A << " B: " << B << endl;
//				cout << "Count: " << count << endl;
//				A += tempA;
//				count++;
//				if(isSubstring(&A, &B)) { // Check if B is substring of A?
//					return count;
//				}
//			}
//			A += tempA;
//			if(isSubstring(&A, &B)) {
//				return count+1;
//			}
//			
//			return -1;
//	    }
//	    
//	    bool isSubstring(string *parent, string *substring) { // Manual .find() Method
//			if(substring->size() > parent->size()) {
//				return false;
//			}
//	    	const char *parCstring = parent->c_str();
//	    	const char *subCstring = substring->c_str();
//	    	for(int i=0; i<strlen(parCstring); i++) {
//	    		cout << "after_i: " << i << endl;
//		    	int j = 0;
//	    		if(parCstring[i] == subCstring[j]) {
//	    			int x = i;
//	    			cout << "x: " << x << " i: " << i << endl;
//	    			if(isEqual(*parent, *substring, i, j)) {
//	    				return true;
//					}
//				}
//			}
//			return false;
//		}
//		
//		bool isEqual(string &parent, string &substring, int x, int y) {
//			while(parent[x] == substring[y] && y<parent.size()) {
//				cout << "par: " << parent[x] << " sub: " << substring[y] << endl;
//    			y++;
//    			x++;
//				if(y == substring.size()) {
//					return true;
//				}					
//			}
//			return false;
//		}
};

int main(void) {
	Solution obj;
	string A = "abcabcabcabc";
	string B = "abac";
//	cout << obj.isSubstring(&A, &B) << endl;
	cout << obj.repeatedStringMatch(A, B) << endl;
	return 0;
}
