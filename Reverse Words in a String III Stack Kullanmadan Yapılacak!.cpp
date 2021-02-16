//QUESTION Link ---> https://leetcode.com/problems/reverse-words-in-a-string-iii/
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
	private:
		string ans;
	public:
	    string reverseWords(string s) {
	        string word = s;
	        istringstream iss(word);
			while(iss >> word) { // Read Word by Word
				reverseWord(word);
			}
			ans = ans.substr(0, ans.size()-1);
			return ans;
	    }
	    
	    void reverseWord(string &word) {
	    	for(int i=word.size()-1; i>=0; i--) {
				ans.push_back(word[i]);
			}
			ans.push_back(' ');
		}
};

int main(void) {
	string A = "Emre Hocam Bu Soruyu Stack Kullanmadan Yap dedi!"; 
	string ret;
	Solution ans;
	ret = ans.reverseWords(A);
	cout << ret << endl;
	return 0;
}
