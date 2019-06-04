//Question Link ---> https://leetcode.com/problems/implement-strstr/
#include <iostream>
#include <vector>
using namespace std;
//Bu kadar fark ettiren nedir ??? Manuel ile bunu arasýnda sorulacak!?
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) {
            return 0;
        }
        
        if(needle.size() > haystack.size()) {
            return -1;
        }
        
		// Find first occurrence
    	size_t found = haystack.find(needle); 
    	if (found != string::npos) {
        	return found; // It is Found!
		}
		//Not Found!
        return -1;
    }	
};

int main(void) {
	string haystack = "hello";
	string needle = "ll";
	Solution obj;
	cout << obj.strStr(haystack, needle);
	return 0;
}
