#include <iostream>
#include <stack>

using namespace std;

class Solution {
	public:
		
		stack<char> list;
		
		char top() {
		    return list.top();
	    }
		
		bool isPair(char open, char close){
			
			if(open == '(' && close == ')'){
				return true; 
			}
			else if(open == '{' && close == '}'){
				return true; 
			}
			else if(open == '[' && close == ']'){
				return true; 
			}
			
			return false; 
		}
		
		bool isValid(string s) {
			
			if(s == "") {
				return true;
			}
			
			if( s.length() == 1 || ( s.length() == 1 && s[0] == ')' || s[0] == '}' || s[0] == ']' ) ) { //If String is Empty
				return false;
			}
			
			else {
				for(int i=0; i<s.size(); i++) {

					if(s[i] == '(' || s[i] == '[' || s[i] == '{') { // Opening
						cout << "pushed: " << s[i] << endl;
						list.push(s[i]);
					}
					
					else if(s[i] == ')' || s[i] == ']' || s[i] == '}') { // Closing
					 cout << "HMMM" << s[i] << endl;
					 		
						if( !list.empty() && isPair(list.top(), s[i]) ) {
							cout << "popped" << list.top() << endl;
							list.pop();
						}
							
						else {
							cout << "returned FALSE!" << endl; 
							return false;
						}
					}
				}
				
				if(list.empty())
					return true;
				
				else
					return false;
			}
		}
};

int main(void) {
	
	Solution obj;
	cout << obj.isValid("((");
	
	return 0;
}
