//QUESTION Link ---> https://leetcode.com/problems/reverse-string/description/
#include <iostream>
#include <stack>
using namespace std;

class Solution {
	public:
	    string reverseString(string s) {
	    	
	        stack<char> stack;
	        
	        for(int i=0; i<s.size(); i++) {
	        	stack.push(s[i]);
			}
			
			for(int i=0; i<s.size(); i++) {
	        	s[i] = stack.top();
	        	stack.pop();
			}
			
			return s;
	    }
};

int main(void) {
	
	Solution obj;
	
	string m = obj.reverseString("hello");
	cout << m;
	
	return 0;
}
