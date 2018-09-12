//QUESTION Link ---> https://leetcode.com/problems/lemonade-change/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	
	vector<int> five, ten, twenty;
	int fiveSum=0, tenSum=0, twentySum=0;	
	
	public:
		
	    bool lemonadeChange(vector<int>& bills) {
	    	
	    	if( bills.size() > 10000 || bills.empty() || bills[0]== 10 || bills[0]== 20 || bills.size() == 0 || bills.size() < 0) {
	    		cout << "FALSE!" << endl; return false;
			}
	    				        
	        else if(bills[0]== 5) {
	        	
//	        	for (int i=0; i<bills.size(); i++)
//						cout << bills[i] << " ";
	        	
	        	for (int i=0; i<bills.size(); i++)  {
	        		
	        		if(bills[i]==5) { // 5
	        			
	        			five.push_back(bills[i]);
	        			fiveSum += 5;
						cout << "->Five's sum: " << fiveSum << endl; 
					}
					
					else if(bills[i]==10) { // 10
						
	        			ten.push_back(bills[i]);
	        			tenSum += 10;
	        			cout << "->Ten's sum: " << tenSum << endl;
	        			
	        			if(fiveSum>=5) {
	        				five.pop_back();
	        				fiveSum -= 5;
						}
						
						else {
							cout << "FALSE!" << endl;
							return false;
						}	
					}
					
					else if(bills[i]==20) { // 20
						
	        			twenty.push_back(bills[i]);
	        			twentySum += 20;
	        			cout << "->Twenty's sum: " << twentySum << endl;
	        			
						if(fiveSum>=5 && tenSum>=10) { // 5 + 10
							five.pop_back();
							fiveSum -= 5;
							ten.pop_back();
							tenSum -= 10;
							cout << "->Ten's sum: " << tenSum << endl;
							cout << "->Five's sum: " << fiveSum << endl;
						}
						
	        			else if(fiveSum>=15) { // 5 + 5 + 5
							for(int i=0; i<3; i++)
								five.pop_back();
								fiveSum -= 15;
								cout << "->Five's sum: " << fiveSum << endl;	
						}
						
						
						else {
							cout << "FALSE!" << endl;
							return false;
						}
					}		
				}
				
				cout << "TRUE!" << endl;
				return true;
			}
	    }
};

int main(void) {
	
	//vector<int> pays = {5,5,10,10,20};	
	vector<int> pays = {5,5,5,5,5,5,5,5,5,5,5,5,5,5,20,5,5,5,5,5,5,5,10,5,20,20,5,5,5,5,5,10,5,5,5,20,5,5,5,10,5,5,10,5,20,5,5,20,5,10,5,5,20,5,5,5,5,5,5,10,20,5,20,20,10,5,20,20,5,10,5,5,5,5,5,5,20,20,20,20,5,5,10,5,20,5,5,5,5,10,10,5,5,5,20,5,5,5,5,5,5,20,5,20,10,10,20,5,5,5,5,20,20,5,5,5,5,20,5,20,20,5,5,10,5,5,5,20,5,5,20,5,5,5,5,5,5,5,5,5,5,5,5,20,5,5,10,20,20,5,5,10,20,5,5,5,5,10,20,5,5,10,20,5,10,10,5,5,5,5,5,5,10,10,10,5,10,5,10,5,5,10,10,5,5,5,20,5,20,10,20,5,5,5,20,10,5,5,20,5,5,5,10,5,5,10,5,5,20,5,10,10,5,5,10,5,5,10,5,10,5,20,10,5,10,10,5,5,5,5,10,5,5,5,20,5,5,5,5,10,5,10,10,5,20,20,5,10,10,10,5,10,5,10,5,10,5,5,10,5,5,5,20,5,5,20,5,5,5,5,5,5,10,5,5,20,20,5,5,5,5,10,5,5,5,20,5,5,5,5,10,20,5,5,5,20,20,5,10,5,5,5,10,5,10,20,20,5,5,5,5,5,5,20,10,5,10,5,5,20,10,5,5,5,20,5,5,5,5,5,5,20,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10,10,5,10,5,10,20,10,10,5,5,20,10,20,5,5,5,10,5,5,5,10,5,20,20,20,10,20,5,5,5,5,20,5,20,5,10,5,5,5,5,5,5,20,5,10,5,5,5,20,5,5,5,10,10,5,5,5,5,5,20,20,20,5,5,5,5,20,5,20,5,20,20,10,10,5,5,5,20,10,20,10,20,5,20,5,5,5,10,10,5,5,5,5,10,10,5,5,5,5,20,5,5,5,5,5,20,10,20,20,5,20,10,5,5,20,5,5,10,5,5,5,5,10,5,5,5,20,5,10,5,10,10,20,5,20,5,20,10,5,5,5,20,5,10,10,5,5,10,5,10,5,5,20,20,5,5,5,5,5,5,5,5,20,5,10,5,10,20,20,5,5,20,5,10,5,20,5,20,20,5,5,5,20,20,20,5,5,5,5,20,10,5,5,10,10,10,5,10,5,10,5,20,5,5,5,5,10,20,5,5,5,5,5,5,20,20,10,10,5,5,20,5,5,5,5,20,20,20,20,5,5,20,20,5,20,5,5,5,10,20,10,5,20,5,5,5,5,10,10,5,10,5,5,10,5,5,20,10,20,5,5,5,10,5,5,10,10,5,20,5,5,20,5,5,20,10,10,5,5,10,5,5,20,5,10,5,20,20,10,10,20,5,5,5,20,5,5,20,20,10,20,10,10,5,20,10,5,10,5,10,5,5,20,5,20,20,5,5,5,5,20,10,5,5,5,5,5,20,5,5,20,10,5,5,5,5,5,5,10,5,10,5,20,20,20,20,5,5,20,5,5,5,20,5,20,5,5,5,10,5,20,5,5,5,5,20,5,20,20,5,5,5,5,10,5,20,20,5,20,5,10,5,5,5,5,20,5,5,5,20,20,5,5,5,20,10,20,5,5,10,5,5,10,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,20,5,20,10,20,20,5,5,10,10,5,10,10,5,5,10,10,5,5,5,5,5,10,5,20,5,10,5,20,10,5,10,5,10,20,10,5,5,5,20,5,5,20,5,5,5,5,5,10,10,20,20,20,5,20,20,5,20,5,5,5,5,5,5,20,5,5,5,5,10,5,5,5,5,10,20,20,5,5,5,5,5,5,5,10,5,5,5,5,5,5,5,5,5,5,5,10,20,20,5,5,5,5,5,5,20,5,5,5,20,5,5,20,5,5,5,5,5,5,5,10,5,10,5,5,5,20,5,5,5,20,5,20,5,20,10,5,5,5,5,10,5,10,5,20,20,10,5,5,20,10,10,5,10,20,5,5,5,10,5,20,5,20,5,5,5,5,5,5,5,5,5,10,5,5,5,20,5,5,10,10,5,5,10,5,10,10,20,10,20,5,5,5,10,10,5,5,20,5,20,5,5,5,5,10,5,20,5,5,5,20,5,5,10,10,5,5,5,20,5,5,10,5,5,5,5,20,5,10,5,5,10,5,10,10,5,10,10,5,20,20,5,5,20,5,5,5,5,5,20,10,10,5,10,5,20,20,5,5,5,5,5,10,5,20,10,20,5,20,5,20,20,5,5,5,5,5,5,5,5,5,20,5,10,5,5,20,20,5,20,20,5,5,5,10,20,5,5,10,10,5,5,20,10,20,5,10,5,5,5,5,20,5,5,5,5,20,20,5,20,5,10,10,5,10,20,20,20,5,5,5,20,5,5,5,5,5,5,5,20,20,5,5,5,5,5,5,5,5,5,20,5,5,5,5,20,10,5,5,5,5,20,5,5,5,5,5,5,5,5,20,10,5,5,5,5,5,10,5,20,5,5,5,5,10,5,10,20,10,20,5,5,5,5,10,5,20,5,20,5,20,5,10,5,10,10,10,5,5,5,20,20,5,5,10,10,10,5,5,20,5,5,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,10,5,5,5,5,5,5,5,20,10,10,20,10,5,5,5,5,5,5,20,5,5,20,5,10,5,20,5,10,5,5,20,5,5,5,10,5,5,5,10,5,5,20,20,5,5,10,20,10,20,5,10,20,5,5,10,5,20,20,5,5,5,5,5,5,5,10,10,10,5,20,20,5,5,20,20,10,20,5,5,5,5,5,5,10,5,5,20,5,20,20,10,5,5,5,5,10,5,10,5,5,5,5,10,20,20,5,5,5,5,20,5,5,5,5,10,20,5,5,10,5,5,10,5,10,20,20,5,10,5,10,5,5,10,10,5,5,5,5,5,5,20,5,20,20,5,5,5,5,5,10,5,5,5,5,5,5,5,20,10,10,5,5,10,5,20,5,5,10,10,20,5,5,5,20,10,5,5,5,10,5,5,5,5,5,20,5,10,5,5,10,20,5,5,20,10,5,5,20,5,5,5,5,10,5,5,5,5,5,5,10,10,5,5,5,5,10,5,20,5,10,10,5,10,5,5,5,5,5,5,10,20,5,5,20,20,5,20,10,5,5,5,10,5,20,5,5,10,20,5,5,20,10,20,10,5,5,5,10,5,5,5,5,5,10,20,10,5,5,5,5,5,5,5,5,20,10,5,20,10,5,20,10,20,10,5,20,5,5,5,5,5,20,20,10,10,10,10,5,5,20,5,10,5,5,10,20,5,5,5,5,20,5,5,5,10,5,5,10,5,20,20,10,10,5,5,10,5,5,10,5,5,20,5,5,5,5,5,5,5,5,5,20,5,10,5,5,5,5,10,5,5,20,10,10,5,20,20,20,5,5,5,5,20,5,10,5,5,5,5,5,10,20,5,20,5,20,5,10,20,5,5,5,5,5,5,5,10,5,20,5,5,20,5,5,5,5,5,20,10,5,10,10,5,20,10,5,20,20,5,5,20,5,5,10,5,5,10,5,5,10,10,5,5,20,10,5,20,5,10,5,5,5,5,5,5,20,5,5,5,20,5,10,5,10,20,10,10,5,5,10,5,20,10,5,5,5,5,5,10,5,5,5,5,5,10,20,20,5,5,5,20,5,5,5,5,10,5,20,5,5,5,20,10,5,5,5,5,10,5,5,5,10,5,5,5,5,20,5,5,5,10,20,20,20,5,20,5,10,5,10,20,5,5,20,5,5,5,5,5,5,5,5,5,20,20,10,5,20,5,5,5,5,5,5,10,5,5,10,5,5,5,5,20,5,5,5,20,5,5,10,5,10,5,10,20,5,5,5,5,20,10,5,5,5,20,5,10,10,5,5,10,20,5,10,5,5,5,20,10,5,20,5,5,5,20,20,10,20,10,5,20,5,10,10,20,10,5,5,10,5,20,20,5,5,5,5,10,5,10,20,20,20,10,20,5,10,5,5,5,10,5,5,5,5,10,5,5,5,20,10,20,5,20,5,5,5,20,10,5,5,20,5,10,5,5,5,10,5,5,10,10,5,20,20,20,5,5,5,5,20,5,20,20,5,10,5,20,5,10,20,5,5,10,5,5,5,5,5,10,10,5,5,5,20,5,10,5,5,5,5,5,20,5,10,10,5,5,10,20,10,5,5,5,5,10,5,5,10,5,10,5,10,5,20,5,5,10,5,20,5,5,10,5,20,5,20,20,10,5,20,10,20,20,5,20,5,20,5,5,20,5,5,5,5,10,5,5,5,5,5,5,5,5,20,20,10,5,5,20,20,20,10,20,20,20,10,10,20,5,10,5,5,10,5,5,5,20,10,20,20,20,5,5,5,10,5,5,5,20,10,5,10,5,5,10,5,5,5,20,5,20,5,5,5,5,5,10,20,10,5,5,5,5,5,10,5,5,5,5,5,10,20,5,10,20,10,10,5,5,20,5,20,5,5,20,5,20,20,5,5,5,10,20,5,5,10,5,5,5,5,5,10,5,5,5,20,5,5,5,5,5,10,5,5,5,5,10,5,20,10,5,5,10,5,5,10,10,10,5,5,10,5,10,5,20,10,20,10,20,20,10,5,10,10,10,5,20,5,5,5,5,10,5,5,20,20,10,10,10,5,10,5,5,20,5,5,5,5,5,5,20,5,5,10,20,5,5,5,20,10,10,10,20,20,10,5,5,10,20,20,10,5,5,5,10,10,5,20,5,10,20,20,5,5,20,10,5,20,5,5,10,5,5,5,10,5,5,10,5,5,10,5,20,5,5,20,5,5,5,20,20,5,20,20,5,5,10,5,5,5,10,5,5,5,5,5,5,10,5,5,10,5,5,5,5,5,5,5,20,5,5,5,5,5,5,20,20,5,10,5,5,5,5,5,10,5,20,10,5,5,20,5,5,5,5,5,5,5,5,20,5,5,5,20,5,10,5,5,20,5,5,20,20,20,20,5,10,5,20,5,5,20,5,5,5,10,5,10,5,20,5,5,5,5,20,5,5,20,20,5,5,20,5,5,5,20,10,5,5,5,5,5,20,20,5,5,5,5,5,10,10,5,10,10,10,5,5,5,20,5,20,10,20,20,5,5,10,5,5,5,10,5,5,5,5,5,5,5,5,10,20,5,5,5,5,5,5,10,10,5,10,10,5,10,5,20,10,10,5,5,20,5,5,10,10,10,5,10,10,10,5,10,5,5,10,5,10,20,20,5,20,5,5,5,10,10,20,5,5,5,10,5,5,5,5,5,20,5,5,10,20,5,20,5,5,10,20,10,20,5,10,5,5,5,10,20,10,5,10,5,5,5,20,5,5,10,5,5,5,5,5,20,10,10,5,20,5,20,5,5,10,5,5,20,5,20,20,10,20,10,5,20,5,20,20,20,5,5,5,10,5,20,20,10,5,20,5,5,5,20,10,5,5,20,20,5,20,20,5,5,5,5,5,5,5,5,10,10,5,5,5,20,5,5,10,20,5,5,5,5,5,5,5,5,20,5,20,5,5,5,5,5,20,5,5,10,10,20,5,20,5,5,5,20,10,5,5,5,5,10,5,20,5,5,5,5,20,20,10,5,5,5,10,5,20,5,10,5,20,5,10,5,5,5,5,5,20,20,5,5,5,5,5,20,10,20,5,5,5,10,5,5,5,20,5,5,5,20,5,5,5,5,5,5,5,10,5,5,20,5,20,5,5,20,10,5,5,5,5,5,5,5,5,5,10,10,5,10,5,10,5,5,10,5,5,10,10,20,5,20,5,5,10,20,5,5,5,5,5,5,20,5,5,5,5,5,20,5,10,5,5,10,5,5,5,5,5,5,20,5,5,5,20,5,5,5,20,10,5,5,10,5,10,5,20,5,10,5,5,20,5,10,5,5,5,10,5,5,5,5,5,20,5,5,5,20,5,10,5,20,5,5,5,10,5,10,5,5,5,5,5,5,5,5,5,5,5,5,10,10,5,20,20,5,5,10,5,5,5,5,10,10,10,5,5,20,5,10,20,5,5,5,5,5,10,10,5,20,5,10,5,5,5,5,20,5,20,10,20,10,10,20,5,5,5,5,5,10,5,5,20,5,5,10,5,5,5,20,20,20,5,10,20,20,10,20,20,20,5,10,20,5,10,5,10,5,20,20,5,5,5,5,5,5,20,5,5,5,5,5,5,5,20,10,5,5,20,5,5,5,20,5,10,20,10,20,5,20,5,5,5,5,20,5,5,5,5,20,5,5,5,5,20,5,5,20,5,20,10,5,5,5,20,10,5,5,5,20,5,10,5,5,5,5,10,5,20,5,5,5,5,5,5,5,5,10,5,10,5,5,5,10,10,5,5,10,20,20,20,20,5,10,5,5,5,5,5,5,5,5,10,10,5,5,20,5,20,5,10,20,5,10,20,5,20,5,10,20,5,20,5,20,20,5,10,5,20,5,5,5,20,10,5,5,5,5,5,5,5,5,10,10,20,5,5,5,5,5,5,5,10,20,10,10,10,20,5,5,10,20,5,20,20,10,5,5,20,5,20,5,20,10,5,10,5,5,5,5,5,10,5,5,10,5,5,20,5,20,5,5,5,5,20,5,5,5,5,5,5,5,10,5,10,20,5,20,5,10,10,5,5,10,5,20,20,5,5,5,10,20,5,5,5,5,10,5,5,5,5,20,5,10,10,5,5,20,5,10,5,20,10,10,5,10,20,5,5,10,5,5,10,5,5,5,5,10,5,5,5,10,5,10,20,20,5,10,5,20,5,10,5,5,20,5,5,20,5,5,20,5,5,10,20,5,5,5,20,20,20,5,20,10,5,5,5,5,5,5,10,5,20,5,10,5,20,5,20,5,20,5,10,5,20,20,10,5,5,10,20,5,5,20,10,5,5,5,5,5,5,5,5,20,10,10,10,10,5,5,5,5,5,10,5,5,5,5,5,5,5,5,5,5,20,5,5,20,20,5,5,5,5,5,5,10,5,20,20,10,20,5,5,5,5,10,20,5,20,5,5,20,5,5,5,5,5,20,20,5,5,5,10,5,5,10,10,10,20,10,5,20,5,5,10,20,5,5,10,5,5,20,5,20,5,5,5,5,5,5,20,5,20,5,5,20,5,5,5,5,20,5,5,5,5,5,20,5,5,5,10,20,10,5,20,20,5,20,5,5,5,5,5,5,5,10,5,5,20,5,10,10,20,10,5,5,10,5,5,10,10,5,5,5,5,5,20,10,5,5,20,5,5,20,5,10,10,20,20,20,10,20,5,20,20,5,5,20,5,20,5,5,20,5,20,5,5,10,5,20,10,5,5,5,5,10,5,20,5,20,20,20,5,10,5,5,5,5,10,20,10,10,20,5,10,5,5,10,5,20,5,20,10,20,5,5,5,5,20,20,5,5,5,10,10,5,5,5,5,5,5,5,5,5,10,5,20,5,5,5,20,5,10,20,5,20,5,5,5,10,5,5,5,5,5,5,5,10,5,10,20,5,5,5,5,5,5,10,5,10,5,10,5,5,5,10,10,20,5,5,10,20,5,20,5,20,10,5,5,5,20,5,10,5,5,5,5,5,20,20,10,5,5,10,5,5,5,10,5,10,10,5,5,5,10,5,10,5,5,5,5,5,10,5,10,10,10,10,5,5,5,5,5,20,10,5,5,5,10,5,5,20,5,5,10,5,5,10,10,10,5,10,20,5,5,20,5,20,5,5,20,5,5,20,20,5,5,20,10,5,5,5,5,5,5,5,10,5,20,5,10,5,5,5,5,5,5,5,10,5,20,10,5,20,5,5,5,5,5,5,20,5,10,5,5,10,20,20,5,5,20,5,5,20,5,10,20,20,5,5,5,5,5,5,20,20,5,10,5,5,5,5,5,5,5,5,20,10,5,5,5,5,5,5,5,5,5,5,20,5,20,20,20,5,5,5,10,10,5,5,10,5,5,5,10,10,5,5,10,10,10,20,5,20,5,5,5,5,5,5,5,10,10,20,5,5,5,5,5,5,5,5,10,5,10,10,5,10,5,5,5,5,10,10,20,10,20,5,10,20,20,20,5,5,10,5,20,20,5,20,20,5,10,5,5,10,20,5,5,5,5,5,10,5,10,5,10,20,5,5,5,5,5,20,10,20,10,20,20,5,5,20,20,5,5,10,5,5,5,20,10,10,5,5,20,5,5,5,20,10,10,5,5,5,10,5,10,10,20,5,10,5,20,5,5,5,20,10,20,5,10,5,20,10,5,5,5,5,5,5,5,20,5,5,20,5,20,5,5,20,5,10,5,5,5,5,5,5,10,5,10,5,5,20,5,10,5,5,5,10,10,5,5,5,20,5,5,20,20,5,5,10,20,5,5,5,5,5,10,20,5,5,10,20,10,20,5,10,5,5,20,20,5,5,5,10,5,5,10,5,5,5,20,20,10,5,5,20,20,5,20,5,10,20,5,5,5,10,5,5,5,10,5,5,20,10,5,20,20,20,5,5,10,5,20,20,20,20,10,5,10,10,10,5,5,5,20,5,10,10,20,5,5,5,5,5,20,5,5,20,10,5,5,20,10,5,10,10,20,10,20,5,5,5,10,10,5,5,10,20,20,5,5,5,10,5,5,20,5,5,5,5,5,10,20,10,5,10,5,5,5,5,5,5,10,5,5,10,10,5,20,5,10,5,5,5,10,5,5,10,20,10,10,20,10,10,20,5,5,5,5,10,5,5,20,20,5,10,20,10,5,5,20,5,20,20,5,5,5,10,5,5,5,5,20,5,5,5,5,5,5,5,5,5,10,10,5,5,5,20,5,5,5,10,20,5,5,5,5,10,5,10,20,5,10,5,5,5,20,5,20,10,5,5,5,5,20,5,5,5,10,5,5,5,5,10,20,5,5,5,10,20,10,10,5,5,20,20,20,10,20,20,10,10,5,5,5,10,5,20,20,5,5,20,20,5,5,20,5,20,5,5,5,5,10,5,10,5,5,10,5,20,5,5,10,10,5,10,5,5,5,5,5,10,5,5,10,10,5,5,5,5,5,20,5,5,5,20,5,5,5,5,5,5,5,5,5,5,5,20,10,20,10,5,5,10,5,5,5,5,5,10,20,20,5,5,5,5,5,5,5,5,5,5,5,5,5,10,10,5,5,10,5,10,20,20,10,5,5,20,5,10,5,5,5,5,20,5,10,20,5,5,10,20,5,5,10,10,20,5,5,5,5,5,20,5,5,5,10,5,5,5,5,5,5,5,20,20,5,5,5,5,5,5,10,10,20,5,5,20,10,5,5,20,20,20,20,20,5,20,10,5,20,5,5,5,5,10,5,20,5,5,10,5,5,10,10,20,5,5,20,5,20,20,5,5,5,5,5,5,5,10,20,10,20,10,5,5,5,10,5,20,20,10,10,20,20,5,5,20,5,10,10,5,5,20,5,20,5,5,5,10,5,5,20,5,10,5,10,5,10,5,10,10,5,20,5,20,5,10,5,5,5,5,20,5,20,5,5,20,10,5,10,10,5,5,5,5,10,5,10,5,10,5,10,20,5,5,10,5,10,5,10,10,20,20,20,20,10,5,5,5,20,5,5,10,10,20,10,5,5,5,5,5,5,5,5,5,10,5,5,5,5,5,20,10,10,10,10,20,10,5,5,5,5,10,20,5,5,5,5,20,5,5,5,10,5,5,10,5,10,10,5,5,5,5,20,20,20,5,20,5,5,10,10,20,5,5,5,5,20,5,20,20,5,5,5,5,5,5,5,5,5,5,10,5,20,20,10,20,5,5,5,20,10,5,10,10,20,20,5,20,10,5,5,5,20,5,5,10,5,5,5,20,10,5,5,5,10,20,5,20,20,5,20,5,5,10,10,10,5,5,20,20,5,5,20,5,5,10,20,10,20,5,5,20,5,10,5,5,5,5,5,20,5,5,5,5,5,20,20,5,20,5,5,5,5,5,5,20,5,5,5,5,5,20,5,20,5,5,20,5,10,5,20,20,5,10,5,5,5,5,10,5,5,5,5,10,5,5,5,10,10,5,20,20,5,5,5,20,10,5,5,5,5,5,10,20,20,20,10,10,5,5,20,10,5,10,5,5,5,5,5,20,5,20,20,5,5,5,10,5,10,10,10,5,5,10,5,5,5,5,5,5,20,5,5,10,5,5,5,5,5,5,10,5,20,20,5,5,5,20,5,5,5,5,10,5,5,10,5,20,5,5,5,20,5,5,5,5,5,5,5,5,10,10,5,10,5,5,5,20,5,10,5,5,10,5,5,5,5,5,20,5,5,5,5,5,20,5,20,20,5,5,5,5,5,10,10,20,5,5,10,5,10,20,10,5,5,5,5,5,20,5,5,5,5,20,20,5,5,5,5,5,20,5,5,20,5,10,20,5,5,5,10,5,10,5,20,10,5,10,5,5,20,20,5,10,5,5,5,10,5,5,20,10,10,20,5,20,5,5,20,5,5,10,20,5,10,20,5,5,5,5,5,5,20,5,10,5,5,20,5,5,20,5,10,5,10,10,5,5,20,5,5,10,5,5,5,10,5,5,5,5,20,5,20,10,5,5,20,5,20,5,5,5,5,5,5,20,5,20,20,5,10,10,20,20,5,5,5,5,5,20,20,20,5,10,5,5,10,5,20,10,10,20,5,5,10,5,5,10,5,5,5,20,5,5,20,5,5,5,5,20,10,5,10,10,10,10,10,5,10,5,5,5,20,10,20,10,5,5,10,5,5,5,5,5,5,5,5,5,20,10,5,5,5,5,5,20,5,20,5,5,20,5,5,20,5,5,5,20,10,20,5,5,10,5,5,5,20,20,5,10,5,5,20,20,5,5,5,10,5,10,5,5,5,20,10,10,5,5,5,5,5,5,5,20,20,5,20,5,10,5,20,10,5,5,10,5,5,5,5,5,5,5,20,20,10,10,5,5,20,5,10,5,5,5,10,5,20,5,5,5,5,5,5,5,10,5,10,5,5,5,5,20,20,5,20,5,20,5,20,5,5,20,5,5,10,20,5,20,5,20,5,5,5,10,10,5,5,20,5,5,10,5,5,10,5,5,5,10,5,5,5,5,5,5,5,10,5,5,10,10,5,5,5,5,10,5,10,10,5,5,5,5,5,5,5,10,5,5,5,5,10,5,5,5,10,5,5,5,10,5,20,5,20,10,5,20,5,5,5,5,5,5,5,5,10,20,5,10,5,5,20,10,5,5,5,10,10,10,5,5,5,5,5,5,20,10,20,20,5,5,20,5,5,5,5,20,5,10,5,10,5,5,20,5,20,5,5,5,5,5,5,5,5,5,10,5,20,10,5,5,5,5,5,20,5,5,5,5,5,5,5,5,5,10,5,20,5,5,5,5,5,5,5,5,10,5,10,10,5,10,5,5,20,5,5,10,5,5,10,20,10,5,20,5,5,5,20,20,5,10,5,5,5,5,10,10,10,20,5,10,5,5,5,5,5,5,5,5,10,5,5,5,5,20,5,10,5,5,5,5,10,5,5,5,20,5,5,20,5,5,5,5,5,10,20,5,20,5,10,10,5,5,20,5,5,5,5,5,20,5,5,5,20,20,5,20,5,5,5,5,20,5,5,5,5,5,20,5,5,10,5,5,5,10,20,20,5,5,5,5,5,10,5,20,20,5,5,5,20,10,5,5,5,10,5,5,5,5,20,20,5,20,10,10,20,5,5,20,5,10,20,20,10,5,5,20,5,5,5,5,5,5,5,5,20,5,5,20,5,5,5,20,5,20,5,5,5,10,10,20,5,5,5,5,10,10,5,20,5,20,5,5,5,5,20,5,20,10,5,20,5,10,10,5,20,5,5,5,10,20,5,5,5,5,5,10,5,5,5,5,20,20,5,20,5,5,10,20,5,10,5,5,5,5,5,5,5,20,5,5,5,10,5,5,5,5,5,5,10,5,20,5,5,5,10,10,20,5,5,5,5,5,5,20,5,5,10,20,20,5,10,20,5,5,20,10,20,5,10,5,5,20,10,5,5,20,10,5,10,10,5,5,20,20,5,20,10,5,5,5,5,5,20,5,5,10,10,10,10,5,5,5,5,5,5,5,20,20,5,20,5,10,20,5,10,5,5,5,10,5,20,5,5,5,5,5,5,10,5,5,5,10,20,5,5,10,5,20,20,10,10,5,5,5,5,10,20,5,10,5,20,10,5,5,20,5,20,10,5,5,5,5,5,10,5,5,5,20,5,20,5,20,5,5,20,10,20,5,20,5,20,5,10,20,20,5,5,5,5,5,10,5,5,5,5,5,5,10,5,5,5,20,5,10,5,5,20,5,5,10,5,5,5,5,20,5,10,5,5,5,5,5,5,5,10,10,5,20,20,5,5,5,5,20,5,20,5,5,5,5,5,10,10,20,20,5,5,5,20,5,5,5,5,5,10,5,5,5,5,5,10,20,5,5,5,20,5,10,5,5,5,5,5,20,5,5,5,10,20,20,5,10,10,5,5,10,5,5,20,10,10,5,5,10,5,5,20,5,5,5,5,20,5,10,10,5,5,10,20,5,5,10,5,5,5,5,5,5,5,10,5,10,10,10,5,20,10,5,5,5,5,5,20,5,5,5,10,20,5,5,5,5,5,10,5,5,5,10,5,20,20,5,20,20,20,5,10,5,5,5,5,20,20,5,5,5,10,5,5,5,10,10,5,5,5,5,5,5,5,10,5,10,5,5,5,5,20,5,20,5,20,5,5,20,5,5,5,20,10,5,5,5,5,5,5,5,10,5,20,5,5,5,5,20,20,5,20,5,10,5,20,5,5,5,5,5,5,5,5,5,5,5,20,20,5,20,10,10,5,5,5,10,5,20,5,20,5,5,5,10,5,5,5,5,5,5,20,10,5,10,5,10,10,10,5,5,5,5,5,10,20,5,5,5,5,5,20,10,10,10,5,10,20,20,20,5,5,10,10,10,20,5,20,5,20,5,5,5,5,20,5,20,5,5,20,5,10,5,20,5,5,5,5,5,5,10,5,5,10,5,20,5,5,5,20,20,10,5,5,20,5,10,5,10,5,5,5,5,20,5,20,5,10,20,10,10,5,5,5,20,5,5,5,5,5,10,5,10,5,5,5,20,20,5,5,10,10,10,5,5,5,5,10,5,5,5,5,20,20,10,5,5,5,5,5,5,20,20,5,10,5,10,10,10,10,5,10,5,5,5,5,5,5,20,5,5,5,5,5,5,5,5,5,5,10,5,10,5,5,5,5,5,20,20,10,20,10,5,5,5,20,5,5,5,20,10,5,10,5,20,5,10,5,5,5,5,5,5,20,5,5,10,5,5,5,5,5,5,5,10,20,10,5,5,5,5,5,10,5,5,5,5,5,5,5,5,5,20,10,10,5,20,5,5,5,10,5,5,10,20,10,5,20,5,20,5,5,20,10,5,20,10,5,5,5,5,10,20,5,20,20,5,5,20,10,5,5,5,10,5,10,20,5,5,5,5,5,10,10,10,10,5,10,20,5,5,20,10,10,10,20,20,20,5,20,10,5,5,10,5,5,10,5,5,5,10,5,10,5,20,20,20,5,10,10,5,5,10,5,5,5,10,20,5,10,10,10,10,20,20,5,5,20,5,5,5,5,10,5,10,5,10,5,10,10,20,5,10,5,10,20,5,5,5,10,5,10,5,5,10,5,5,5,5,10,5,20,5,5,5,5,10,10,5,20,5,5,5,10,5,10,20,5,5,20,10,5,5,5,5,5,20,5,5,5,5,5,5,5,5,10,5,5,10,20,5,20,5,10,5,5,10,5,10,5,5,5,20,10,5,5,5,5,20,10,5,5,5,5,20,5,5,5,10,5,10,5,5,5,5,10,5,5,5,5,5,5,10,5,5,5,5,10,5,20,10,20,5,5,20,10,5,5,10,10,10,5,10,20,5,5,5,5,10,5,20,5,5,5,5,5,10,5,5,5,5,20,5,20,20,5,5,10,5,5,20,10,10,5,10,20,5,10,5,5,5,10,5,5,20,5,20,20,5,5,5,20,5,5,20,5,5,5,20,5,5,5,10,5,10,10,20,20,5,5,20,5,10,20,10,5,5,5,5,10,5,5,20,5,5,5,5,5,5,10,20,20,5,5,10,20,5,5,5,10,5,5,5,20,5,5,20,5,5,5,5,5,5,5,5,20,20,5,5,5,5,5,5,20,5,5,20,10,5,10,5,5,20,10,10,5,20,20,5,5,5,5,5,5,5,20,10,5,5,5,20,10,10,5,5,5,10,10,5,10,5,5,5,20,10,5,10,20,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10,5,5,5,5,20,10,5,5,20,20,5,20,5,10,5,10,20,10,5,10,5,5,20,5,5,5,5,20,5,10,5,5,5,20,20,5,10,10,5,10,10,20,10,5,5,10,20,5,5,10,5,5,5,20,5,5,5,5,5,20,5,20,10,10,5,5,5,20,5,5,20,10,5,5,5,10,5,10,5,5,5,10,5,5,20,5,10,5,10,10,5,5,10,20,20,5,5,10,10,10,5,5,5,10,5,5,5,10,5,10,5,10,20,5,20,10,20,10,5,5,5,20,5,5,20,5,5,5,5,5,10,10,5,5,5,5,10,5,5,20,20,5,10,5,5,5,5,20,5,5,20,5,10,20,20,20,5,5,20,5,10,5,5,5,5,20,10,20,10,5,5,5,10,20,5,20,5,20,10,20,20,5,10,10,5,20,5,20,5,20,5,20,5,20,20,5,5,5,5,20,20,5,5,10,5,5,20,5,5,5,10,10,5,5,5,5,5,20,20,5,10,10,10,20,5,20,20,5,5,20,20,5,5,5,10,5,20,20,10,5,5,10,5,10,10,5,5,10,5,5,5,20,5,10,5,20,5,20,5,5,20,20,10,20,5,5,5,5,5,5,20,10,5,5,5,5,5,10,20,5,5,20,5,5,5,5,5,5,20,5,5,10,10,5,5,20,20,5,5,5,20,5,5,5,5,5,5,5,20,5,5,5,10,10,5,10,10,5,5,10,10,10,20,10,10,5,5,5,10,5,5,10,10,5,10,5,5,5,10,20,5,20,20,10,5,10,5,10,5,5,5,5,5,5,5,5,5,5,5,10,10,20,5,5,20,5,5,10,20,20,20,5,5,5,5,10,10,5,5,5,5,5,20,20,5,20,5,5,20,5,5,5,5,5,5,5,20,5,10,20,5,5,10,5,5,5,20,20,5,10,5,10,10,5,5,10,5,5,20,20,20,20,5,5,5,10,20,10,10,10,5,10,5,5,20,5,10,5,10,5,5,20,5,5,20,5,20,5,20,20,5,20,5,5,20,5,5,5,20,5,10,5,5,20,5,20,5,20,20,20,5,5,20,5,5,10,10,5,5,5,5,10,10,5,20,10,20,5,5,5,5,5,5,5,5,5,5,5,5,10,5,5,10,5,20,5,5,20,5,10,20,5,5,10,5,5,5,5,10,5,20,5,20,5,5,5,10,10,5,5,10,5,20,20,10,5,10,5,5,5,10,5,10,5,5,10,10,5,5,20,10,5,5,5,20,5,5,20,5,5,5,20,10,10,20,10,5,10,5,5,10,5,10,10,5,5,20,10,5,10,5,5,20,20,5,20,5,5,5,5,5,20,10,5,5,5,10,10,10,5,5,20,5,5,10,5,5,5,20,5,5,5,10,5,20,10,5,5,10,5,5,10,5,5,10,5,20,5,5,5,5,20,5,20,20,5,5,5,5,5,10,10,5,5,5,20,5,20,10,5,20,5,5,5,5,5,5,10,10,5,10,10,5,5,20,5,5,20,20,10,20,5,10,5,20,10,10,10,5,5,10,5,10,5,20,5,10,5,5,10,5,5,5,10,5,5,10,10,20,5,5,5,5,5,5,5,5,5,5,5,20,5,10,5,5,5,5,5,5,5,20,10,5,5,10,5,5,10,10,20,20,5,10,10,5,5,5,5,20,5,5,5,5,5,5,10,5,5,5,10,20,20,5,5,20,20,5,10,20,10,5,5,10,20,10,5,20,10,10,5,5,5,5,10,5,5,5,5,20,5,5,10,10,5,20,20,5,20,10,5,20,5,5,5,20,5,5,20,20,20,5,20,20,5,10,5,10,5,5,5,10,5,20,10,5,5,5,5,20,10,5,10,10,5,5,5,5,5,5,20,20,10,10,5,10,20,20,5,20,5,20,10,5,5,5,5,10,5,5,5,5,20,5,5,5,5,5,20,5,5,5,20,10,10,20,5,5,20,10,10,5,10,5,10,5,5,20,5,5,5,5,5,10,5,10,5,5,5,5,5,20,5,10,10,10,5,5,5,10,5,20,5,5,5,10,5,5,5,5,10,5,10,5,5,10,20,5,5,10,10,20,20,20,20,10,20,5,5,5,5,5,5,5,20,5,10,5,10,20,5,20,5,5,5,5,5,20,5,5,5,20,5,20,20,20,5,5,10,5,5,5,5,5,5,5,5,10,5,20,10,5,10,10,5,5,20,20,10,5,10,10,20,10,5,5,10,10,5,10,5,5,5,10,5,5,10,10,10,5,20,5,20,5,5,5,5,5,5,5,5,5,5,5,5,5,10,5,5,5,5,10,5,10,10,5,5,5,20,10,5,5,10,20,20,20,5,10,10,20,20,5,20,5,5,20,5,10,5,20,20,10,5,5,10,5,5,5,10,5,5,10,10,5,20,5,10,10,5,5,10,10,5,5,5,5,10,5,10,20,5,5,10,5,20,5,20,5,5,10,5,5,5,5,5,5,5,20,20,20,5,20,5,20,10,5,5,5,5,5,5,20,5,20,5,5,5,5,10,5,5,5,5,20,5,5,5,10,5,5,10,20,5,20,5,10,5,20,20,10,20,5,10,5,5,10,10,20,5,20,5,20,5,20,20,20,5,20,5,20,5,5,10,20,5,10,5,5,10,5,5,20,10,10,10,5,5,5,5,5,10,5,10,10,20,5,5,5,5,5,10,10,10,5,10,20,20,5,5,20,20,5,20,5,5,5,10,10,5,5,5,10,20,5,10,5,5,10,5,10,5,10,10,5,20,5,5,10,5,5,10,10,20,5,20,20,20,5,5,10,20,5,20,5,20,5,5,10,5,20,10,20,5,10,5,10,10,5,20,5,20,5,5,5,10,5,5,20,5,5,5,5,5,10,10,20,5,20,20,5,5,10,5,5,20,5,5,10,5,5,5,5,5,5,5,5,5,10,5,5,5,5,5,5,5,5,20,10,20,5,5,5,10,5,20,5,10,5,5,10,5,5,5,10,10,5,5,10,5,5,20,20,20,5,5,20,20,10,5,5,10,5,5,5,20,5,5,20,5,20,5,20,5,5,5,10,5,20,20,5,10,10,5,5,5,5,5,5,10,20,5,5,5,20,5,5,5,20,5,5,5,5,10,20,10,5,5,5,10,5,20,20,10,10,5,10,5,20,20,5,5,5,10,5,20,5,5,20,5,5,10,20,5,20,20,5,5,20,20,20,20,5,5,10,5,20,5,5,5,5,10,5,5,5,5,10,5,5,5,10,5,5,5,5,5,5,5,10,20,20,20,5,5,10,5,5,10,5,5,20,5,10,5,10,10,5,5,20,5,10,20,5,5,10,20,5,5,5,5,5,5,5,10,5,5,10,5,5,10,10,5,5,20,5,10,5,20,5,20,20,5,20,5,5,5,5,5,20,5,5,5,5,5,20,10,20,10,5,20,20,10,5,20,5,5,5,5,5,5,5,5,10,20,5,10,5,5,5,5,5,5,5,5,10,5,5,20,10,5,5,10,10,5,5,5,5,5,5,5,5,5,20,20,20,5,5,20,20,10,5,10,5,10,5,5,5,10,5,5,20,5,20,5,10,10,5,5,5,10,5,5,5,5,5,5,5,20,5,20,5,5,5,20,5,20,5,5,5,5,5,20,5,5,20,5,10,5,5,20,5,5,5,5,5,10,10,10,5,5,5,10,10,5,20,5,10,5,5,5,5,20,20,20,5,5,5,20,20,10,5,5,5,10,5,5,5,5,5,20,5,5,20,5,10,20,5,10,5,10,10,10,10,5,10,5,5,5,5,5,5,20,5,5,5,20,5,5,20,5,5,5,20,5,5,5,5,5,10,10,5,5,5,5,5,20,10,10,5,10,10,20,10,5,20,10,10,5,5,20,5,5,5,5,20,5,5,5,5,10,20,5,20,20,5,20,5,10,10,5,5,10,20,5,5,5,5,20,20,5,5,5,5,10,5,5,10,5,5,5,5,5,10,5,5,10,5,10,10,10,10,5,20,5,5,5,10,5,5,5,5,5,5,5,10,5,5,5,5,20,10,10,5,5,5,5,5,20,5,5,5,20,5,10,10,5,5,5,5,5,20,5,20,5,5,5,5,5,10,5,10,5,5,5,5,5,10,5,5,10,5,5,5,5,5,5,10,5,5,5,5,5,5,20,5,5,5,10,20,20,5,20,20,10,10,5,5,5,5,10,10,5,10,5,10,10,5,20,5,5,20,5,5,10,5,20,5,5,5,5,20,5,5,20,5,10,5,5,20,10,10,20,10,20,20,10,20,5,10,5,20,10,5,10,5,5,10,5,5,20,5,5,10,10,10,5,5,20,5,5,5,20,5,10,10,5,5,10,5,5,5,5,5,5,5,5,20,5,5,5,10,5,5,5,20,5,20,10,10,20,20,5,20,20,10,20,5,5,5,20,5,5,5,5,20,5,10,5,10,5,5,5,20,20,5,5,10,20,10,5,5,5,10,10,5,10,20,10,10,5,5,5,20,5,5,5,5,5,5,20,5,20,20,5,5,5,20,20,5,5,20,5,10,20,20,5,20,10,10,5,5,5,10,5,10,5,5,5,20,5,20,10,5,5,5,5,5,5,5,10,10,10,5,10,5,5,5,20,20,20,5,5,5,5,5,20,5,20,5,5,5,5,5,20,5,5,5,5,10,10,5,10,20,5,10,20,10,5,5,5,5,20,5,10,5,20,5,5,5,20,5,5,10,5,5,10,5,10,10,5,5,5,5,20,5,20,20,10,5,5,5,5,5,5,5,10,5,5,5,5,5,5,5,5,5,5,5,5,5,5,20,5,5,5,5,5,20,5,10,10,5,5,5,20,5,5,5,20,10,20,5,5,20,10,5,5,5,20,10,5,20,5,5,5,20,5,5,5,20,5,20,5,10,5,5,10,10,10,10,5,5,5,20,20,5,5,5,5,5,5,5,20,5,5,5,5,5,10,5,5,5,5,5,5,5,5,20,20,5,5,20,5,5,5,5,20,5,5,10,10,5,5,5,5,10,5,5,20,5,5,5,20,5,5,5,5,20,10,5,5,5,5,10,5,5,10,20,5,5,20,5,10,5,5,20,10,5,5,20,10,20,20,5,5,20,10,10,20,5,20,5,10,10,10,5,10,5,10,5,5,5,10,5,5,10,5,5,20,20,10,10,5,5,10,20,5,5,5,10,5,10,5,5,5,5,5,5,20,5,5,10,5,5,5,5,20,5,5,5,20,5,20,5,5,5,10,5,10,20,5,20,5,10,20,10,5,5,20,10,5,10,5,10,20,20,5,20,5,5,10,5,10,20,10,20,10,5,5,5,20,5,5,5,5,5,20,5,10,10,5,20,5,5,5,20,10,5,10,5,5,5,5,5,10,10,5,5,10,20,20,20,5,10,5,5,5,20,5,5,5,20,5,5,5,5,10,5,5,5,5,10,20,5,20,5,5,5,5,20,20,20,5,5,10,20,5,5,5,5,5,5,5,10,20,5,5,5,20,5,5,10,20,20,10,5,5,5,5,20,5,5,20,20,5,5,10,20,5,5,20,5,5,10,5,10,5,10,20,10,5,5,10,5,5,5,5,5,5,20,20,20,5,5,5,5,10,20,5,10,20,5,5,5,10,20,5,10,5,5,5,5,5,10,5,5,5,20,5,5,20,5,20,5,20,10,10,5,5,20,5,5,5,5,20,20,5,5,20,20,5,5,5,10,20,5,5,5,5,5,5,10,5,5,5,10,5,5,5,5,10,5,5,5,20,5,5,10,5,5,5,5,20,10,10,5,10,10,5,20,5,5,5,5,10,5,20,20,5,5,10,10,20,20,5,5,5,5,5,5,5,5,20,5,5,20,5,5,10,10,20,5,20,5,20,10,5,20,10,5,10,5,5,5,5,5,10,5,5,20,5,20,5,5,20,10,10,5,10,10,5,10,5,5,5,10,10,5,5,20,10,10,10,5,5,20,5,5,20,5,5,5,20,5,5,5,10,10,5,5,5,20,20,20,5,20,5,20,5,10,5,5,5,20,5,20,10,20,5,10,5,5,20,5,5,20,10,5,5,5,5,10,10,5,5,20,20,5,10,20,5,10,5,20,5,5,10,10,5,5,5,20,5,5,5,5,10,20,5,10,5,20,5,5,5,10,5,5,5,5,20,20,5,5,10,20,5,5,5,20,5,5,10,5,10,20,10,20,10,20,5,5,20,5,5,5,5,20,10,5,5,5,5,5,5,5,5,20,5,20,5,20,10,5,10,10,20,10,20,5,10,10,20,5,5,5,5,5,5,5,20,20,5,20,20,20,5,5,5,5,10,5,5,5,5,20,5,5,20,10,5,5,5,5,5,5,20,5,5,5,10,10,5,20,10,20,10,20,5,5,5,20,5,5,5,20,10,20,5,5,5,20,5,5,5,5,5,20,5,5,10,5,5,5,5,5,20,20,5,5,5,5,5,5,5,5,20,10,5,5,20,5,5,20,20,20,5,10,10,5,5,5,5,10,20,10,10,5,5,5,5,5,20,10,5,20,10,5,10,5,5,20,5,5,5,10,5,5,5,20,5,20,5,5,5,5,5,5,5,5,10,10,5,10,10,5,5,5,20,5,5,10,5,5,5,20,20,20,20,5,5,5,5,10,5,20,5,5,20,20,5,5,20,10,10,5,5,5,20,5,5,5,5,5,10,5,20,20,5,5,5,10,20,5,20,5,20,5,5,5,5,5,5,5,20,20,20,5,5,20,20,10,5,5,5,5,5,5,5,5,20,5,20,10,20,5,5,5,5,5,5,10,5,5,10,5,5,5,5,5,20,5,5,5,5,5,10,5,5,10,10,5,10,10,5,5,20,20,5,5,5,5,5,10,5,20,10,5,5,5,5,5,5,5,5,5,10,20,20,5,20,5,20,20,20,10,20,10,5,5,10,10,20,5,5,5,5,5,10,5,10,5,5,5,5,5,5,20,5,5,5,20,20,20,10,5,5,10,5,5,10,5,5,20,10,20,5,5,20,20,10,20,20,5,5,5,5,5,5,5,10,5,10,10,5,10,5,20,20,10,10,5,5,20,10,5,10,10,5,5,5,5,10,5,5,20,5,5,5,5,10,5,10,5,10,5,5,5,5,10,5,5,20,5,5,5,5,5,10,20,5,10,5,10,20,10,20,20,5,5,5,5,5,20,5,10,10,5,20,5,20,10,20,10,5,10,5,5,5,5,5,5,5,5,20,5,5,5,5,5,5,20,5,5,5,10,5,5,5,5,5,5,5,10,5,10,10,20,5,20,5,5,20,5,20,5,5,5,20,10,10,5,5,5,5,5,20,10,10,5,5,5,20,10,5,10,5,5,20,10,5,5,5,5,5,5,20,5,20,5,10,10,5,5,5,5,10,5,5,5,5,10,5,10,5,10,5,10,5,5,5,5,20,5,5,20,5,5,10,5,5,5,5,10,5,5,10,5,20,5,5,5,10,10,5,20,5,5,10,5,5,10,20,5,5,5,5,10,20,20,20,5,5,10,20,5,5,5,10,5,20,5,5,5,20,5,5,5,5,5,5,20,5,20,5,10,5,20,20,10,10,5,5,10,5,5,5,5,5,5,10,20,10,10,5,5,5,5,5,20,5,5,5,5,5,5,5,5,10,5,20,10,20,20,5,5,5,5,5,5,10,5,5,5,10,20,10,20,5,10,5,5,5,5,5,5,10,10,5,5,10,20,10,5,5,5,5,20,5,5,20,5,5,10,5,5,5,5,5,5,10,20,5,20,20,10,10,10,20,10,20,5,5,10,10,5,20,5,5,10,5,5,5,5,5,5,5,10,20,10,10,5,10,20,5,5,20,5,10,5,5,10,5,20,10,10,10,5,5,5,5,5,5,5,20,5,5,20,10,5,5,20,5,5,5,5,20,20,5,10,5,20,5,5,5,5,5,5,20,10,20,20,10,5,5,5,5,5,5,20,5,10,5,5,5,5,5,10,5,5,5,20,20,5,10,20,20,20,10,20,5,5,5,5,20,5,5,5,5,20,5,5,5,5,20,5,20,5,5,5,5,5,5,10,5,5,5,5,5,10,5,10,5,10,5,5,20,10,20,10,20,5,5,5,5,5,10,20,10,20,20,10,5,5,10,5,5,10};
	
	Solution obj;
	
	cout << obj.lemonadeChange(pays) << endl;
	

		
	return 0;
}