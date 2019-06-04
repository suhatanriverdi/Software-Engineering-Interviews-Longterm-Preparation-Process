//Question Link ---> https://leetcode.com/problems/unique-morse-code-words/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
	vector<string> alphabet = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
//	a b c d e f g h i j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
//  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
	public:
	    int uniqueMorseRepresentations(vector<string>& words) {	  
	    	unordered_set<string> morset;
			vector<string> mors(words.size());
			for(int i=0; i<words.size(); i++) {
				for(int j=0; j<words[i].size(); j++) {
					mors[i].append(alphabet[(words[i][j] - 'a')]);
				}
			}

			for(int i=0; i<mors.size(); i++) {
				morset.insert(mors[i]);
			}
			
			return morset.size();   
	    }
};

int main(void) {
	vector<string> words = {"gin", "zen", "gig", "msg"};
	Solution obj;
	cout << obj.uniqueMorseRepresentations(words) << endl;
	return 0;
}
