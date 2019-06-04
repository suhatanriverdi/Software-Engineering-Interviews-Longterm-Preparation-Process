//Question Link ---> https://leetcode.com/problems/first-unique-character-in-a-string/
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {

    	unordered_map<char, int> unique;
    	for(int i=0; i<s.size(); i++) {
			++unique[s[i]];
		}
		
		for(int i=0; i<s.size(); i++) {
			if(unique[s[i]] == 1) {
				return i;
			}
		}
		
        return -1;
    }
};

int main(void) {
	string s = "aadadaad";
	Solution obj;
	cout << obj.firstUniqChar(s) << endl;
	return 0;
}
