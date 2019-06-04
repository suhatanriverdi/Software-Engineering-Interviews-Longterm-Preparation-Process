//Question Link ---> https://leetcode.com/problems/implement-strstr/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) {
            return 0;
        }
        
        if(needle.size() > haystack.size()) {
            return -1;
        }
        
	    for(int i=0; i<haystack.size(); i++) {
            if(haystack[i] == needle[0]) {
                if(isOccurence(i+1, 1, haystack, needle)) {
                    return i;
                }
            }
        }
        return -1;
    }
    
    bool isOccurence(int hStart, int nStart, string haystack, string needle) {	
   	    for(int i=nStart; i<needle.size(); i++, hStart++) {
            if(haystack[hStart] != needle[i]) {
				return false;
            }
        }
        return true;
    }	
};

int main(void) {
	string haystack = "hello";
	string needle = "ll";
	Solution obj;
	cout << obj.strStr(haystack, needle);
	return 0;
}
