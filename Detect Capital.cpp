//QUESTION Link ---> https://leetcode.com/problems/detect-capital/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 0) {
        	return false;
		}
		
		if(word.size() == 1) {
			return true;	
		}
		
		if(word[0] >= 'A' && word[0] <= 'Z') { // A...
			if(word[1] >= 'A' && word[1] <= 'Z') { // AB...
				for(char &c : word) {
					if(c >= 'A' && c <= 'Z') {
					}
					else {
						return false;
					}
				}
				return true;
			}
			
			if(word[1] >= 'a' && word[1] <= 'z') { // Ab...
				for(auto it = word.begin()+1; it != word.end(); it++) {
					if(*it >= 'a' && *it <= 'z') {
					}
					else {
						return false;
					}
				}
				return true;
			}
		}
		
		else { // a...
			for(char &c : word) {
				if(c >= 'a' && c <= 'z') {
				}
				else {
					return false;
				}
			}
			return true;
		}
    }
};

int main(void) {
	Solution obj;
	string s = "Aasd";
	cout << obj.detectCapitalUse(s);
	return 0;
}
