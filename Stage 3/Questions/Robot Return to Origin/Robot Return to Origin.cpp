//QUESTION Link ---> https://leetcode.com/problems/robot-return-to-origin/description/
#include <iostream>
#include <stack>
using namespace std;

class Solution {
	
	public:
		
		int u=0, d=0, l=0, r=0;
		
	    bool judgeCircle(string moves) {
	    	
	    	for(int i=0; i<moves.size(); i++) {
	    		
		        switch(moves[i]) {
		        	case 'U':
		        		u++;
		        		break;
		        	case 'D':
		        		d++;
		        		break;
		        	case 'R':
		        		r++;
		        		break;
		        	case 'L':
		        		l++;
		        		break;		        	
				}
			}
			
			if((u-d) == 0 && (l-r) == 0)
				return true;
				
			return false;
	    }
};

int main(void) {
	
	Solution obj;
	
	cout << obj.judgeCircle("UDRL");
	
	return 0;
}
