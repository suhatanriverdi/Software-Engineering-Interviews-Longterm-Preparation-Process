//QUESTION Link ---> https://leetcode.com/problems/shortest-distance-to-a-character
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	    vector<int> shortestToChar(string S, char C) {
	        vector<int> res(S.size(), S.size());
	        vector<int> charCount;
	        
	        for(int i=0; i<S.size(); i++) {
	        	if(S[i] == C) {
	        		charCount.push_back(i);
				}
			}
	        
	        for(int i=0; i<charCount.size(); i++) {
	        	for(int j=0; j<S.size(); j++) {
					res[j] = min(res[j], abs(charCount[i]-j));
				}
			}   
			   
	        return res;
	    }     
};

int main(void) {
	vector<int> answer;
	Solution obj;
	string s = "loveleetcode";
	char c = 'e';
	answer = obj.shortestToChar(s, c);
	for(int i=0; i<answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return 0;
}
