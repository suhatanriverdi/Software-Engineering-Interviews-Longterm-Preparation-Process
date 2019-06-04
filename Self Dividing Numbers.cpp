//QUESTION Link ---> https://leetcode.com/problems/self-dividing-numbers/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	    vector<int> selfDividingNumbers(int left, int right) {
	        vector<int> res;
	        for(int i=left; i<=right; i++) {
	        	if(canBeGetDigits(i)) {
	        		cout << i << " can be divided\n";
					res.push_back(i);	
				}
			}
	        return res;
	    }
	    
	    // Gets each digit from the number, Do not return the numbers ending with "0"
	    bool canBeGetDigits(int num) {
	    	int digit, backup = num;
	    	
	    	// If number is between 1 and 9
	    	if(num>=1 && num<=9) {
	    		cout << "Num: " << num << endl;
	    		return true;
			}
			
			// We do not want the numbers ending with "0"
			if(num%10 == 0 || num%100 == 0 || num%1000 == 0 || num%1000 == 0 || num%10000 == 0) {
				cout << "Num ending with '0' " << num << endl;
				return false;
			}
	    	
			while(num>0) {
				digit = num%10;
				cout << "Backup: " << backup << endl;
				cout << "Digit: " << digit << endl;
				
				if(!canBeDivided(digit, backup)) {
					return false;
				}
				num = num/10;
			}
			return true;
		}
		
		bool canBeDivided(const int &digit, const int &number) {
			if(digit != 0 && number%digit == 0) {
				return true;
			}
			return false;
		}
};

int main(void) {
	Solution obj;
	int left = 66, right=708;
	vector<int> answer;
	answer = obj.selfDividingNumbers(left, right);
	cout << endl << endl;
	for(int i=0; i<answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return 0;
}
