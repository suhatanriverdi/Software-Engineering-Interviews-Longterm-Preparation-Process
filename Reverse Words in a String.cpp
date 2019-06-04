// Question Link ---> https://leetcode.com/problems/reverse-words-in-a-string/
//Input: "the sky is blue", 1 2 3 4
//Output: "blue is sky the". 4 3 2 1
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
    	if(s.size() == 0) {
    		return;
		}
		
		if(fullOfSpaces(s)) {
			s = "";
			return;
		}
    	
    	string word;
        stack<string> bucket;
        for(int i=0; i<s.size(); i++) {
        	if(s[i]!=' ') {
				//cout << s[i];
				word.push_back(s[i]);
			}
			else {
				//cout << word << endl;
				//word.insert(word.begin(), ' ');
				if(word.size()) {
					bucket.push(word);
					word.clear();
				}
			}
		}
		if(word.size()) {
			bucket.push(word);
			word.clear();
		}
	
        int spaceSize =	bucket.size()-1;
        cout << "spaceSize: " << spaceSize << endl;
        cout << "stackSize: " << bucket.size() << endl;
        while(!bucket.empty()) {
			//cout << bucket.top() << endl;
        	word.append(bucket.top());
        	if(spaceSize) {
        		cout << "ifs" << endl;
        		word.append(" ");
        		spaceSize--;
			}
        	bucket.pop();
		}
		
		//word.erase(word.size()-1);		
		s = word;
    }
    
    bool fullOfSpaces(string s) {
    	int i=0;
    	while(s[i]!='\0') {
    		if(s[i] != ' ') {
    			return false;
			}
			i++;
		}
		return true;
	}
};

//Input: "the sky is blue", 1 2 3 4
//Output: "blue is sky the". 4 3 2 1

int main(void) {
//	string s = "the sky is blue";
//	string s = " ";
	string s = " 1";
	Solution obj;
	obj.reverseWords(s);
	cout << s << "." << endl;	
}
