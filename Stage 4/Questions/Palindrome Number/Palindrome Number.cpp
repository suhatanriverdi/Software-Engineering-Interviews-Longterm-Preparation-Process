#include <iostream>
#include <math.h>
using namespace std;

class Solution {
	public:
    	bool isPalindrome(int x) {
    		
			long long ret, x1=x;
			
			if(x == 0) { // If x == 0
				return true;
			}
			
			else if(x < 0)
				return false;
			
			else { // If x has at least two-digit
				ret = reverse(x);
					
				if(ret==x1)
					return true;
				return false;
			}	
    	}
    	
		int reverse(int x) {
		        
	        bool isNegative=false;
	        
	        if(x<0) {
				x *= (-1);
	        	isNegative = true;
			}
				
	        long long sum=0;
	        bool once=true;
	        int size = to_string(x).length()-1;

	        while(x > 0){
	        	
	        	if(x%10 != 0) {
                    
					sum += x%10*pow(10,size);
				}
				size--;
	        	x /= 10;
			}
			
	        if (sum > 2147483647) {
	            sum = 0;
	        }
	        
			if(isNegative)
				return  sum*= (-1);
				
			return sum;
		}
};

int main() {

	int target = -121;

	Solution obj;
	cout << obj.isPalindrome(target);

    return 0;
}
