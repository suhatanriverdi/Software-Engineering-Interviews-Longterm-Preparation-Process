#include <iostream>
#include <math.h>
using namespace std;

//integer = 16 bit
//long long = at least 32 bit

class Solution {
	
	public:
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

int main(void) {

	int x = 1534236469;
	Solution obj;
	
	cout << "old: " << x << endl << endl;
	cout << "reversed: " << obj.reverse(x);	
	
	return 0;
}
