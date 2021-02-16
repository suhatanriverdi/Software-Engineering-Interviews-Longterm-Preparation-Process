//Question Link ---> https://leetcode.com/problems/reverse-only-letters/
#include <iostream>
using namespace std;
//  01234
// "ab-cd"
class Solution {
	public:
	    string reverseOnlyLetters(string S) {
			int first = 0; 
			int last = S.size()-1;		
			while(first < last){
				if(isalpha(S[first]) && isalpha(S[last])) {
					swap(S[last], S[first]);
					first++;
					last--;
					continue;
				}
				
				else if(isalpha(S[first]) && !isalpha(S[last])) {
					last--;
					continue;
				}
				
				else if(!isalpha(S[first]) && isalpha(S[last])) {
					first++;
					continue;
				}
				
				else {
					first++;
					last--;
					continue;
				}
			}	
			cout << S << endl;
			return S;
	    }
};

int main(void) {
	string s = "ab-cd";
	Solution obj;
	obj.reverseOnlyLetters(s);
//	cout << obj.reverseOnlyLetters(s) << endl;
	return 0;
}
