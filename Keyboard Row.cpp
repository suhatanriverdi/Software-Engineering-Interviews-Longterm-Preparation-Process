// Question Link ---> https://leetcode.com/problems/keyboard-row/description/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
	public:
		unordered_set<char> one = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};
    	unordered_set<char> two = {'a', 's', 'd' , 'f', 'g', 'h', 'j', 'k', 'l',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
    	unordered_set<char> three = {'z', 'x', 'c', 'v' , 'b', 'n', 'm',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
    	unordered_set<char>::const_iterator it;
		vector<string> ans;
		
		void setCheck(unordered_set<char> &set, string &word) { // Now we know which set we must search in 
			for(int i=1; i<word.size(); i++) { // For each letter, skip first letter	
				it = set.find(word[i]);
				if(it == set.end()) { // If not found
					return;
				}			
			}
			ans.push_back(word);
		}
		
		void rowCheck(string &word) {
			for(int i=0; i<word.size(); i++) {
				it = one.find(word[i]);
				if(it != one.end()) { // Found! in One
					setCheck(one, word);
					return;
				}
				
				it = two.find(word[i]);
				if(it != one.end()) { // Found! in Two
					setCheck(two, word);
					return;
				}
				
				it = three.find(word[i]);
				if(it != one.end()) { // Found! in Three
					setCheck(three, word);
					return;
				}			
			}
		}

	    vector<string> findWords(vector<string> &words) {
	  		for(int i=0; i<words.size(); i++) { // For each word
	  			rowCheck(words[i]); // For each word in vector	
			}
	  		return ans;
	    }
};

int main(void) {
	vector<string> ans = {};
	vector<string> test = {"Hello", "Alaska", "Dad", "Peace"};
	Solution obj;
	ans = obj.findWords(test);
  	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}
