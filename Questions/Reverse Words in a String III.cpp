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
		while(iss >> word) {
			reverseWord(word);
		}
		ans = ans.substr(0, ans.size()-1);
		return ans;
    }
    
    void reverseWord(string &word) {
    	stack<char> stack;
    	for(int i=0; i<word.size(); i++) {
    		stack.push(word[i]);
		}
		
		while(!stack.empty()) {
			ans.push_back(stack.top());
			stack.pop();
		}
		ans.push_back(' ');
	}
};

int main(void) {
	string A = "Let's take LeetCode contest"; 
	string ret;
	Solution ans;
	ret = ans.reverseWords(A);
	cout << ret << endl;
	return 0;
}
