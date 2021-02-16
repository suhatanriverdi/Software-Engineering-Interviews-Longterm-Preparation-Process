//Question Link ---> https://leetcode.com/problems/unique-email-addresses/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
	public:
		unordered_set<string> uniques;
	    int numUniqueEmails(vector<string>& emails) {
	        for(int i=0; i<emails.size(); i++) {
	        	uniques.insert(removeDots(emails[i]));
			}
			return uniques.size();
	    }
	    
	    string removeDots(string &str) {
			string res;
			bool key = false;
			int index = 0;
			for(int i=0; i<str.size() && str[i] != '@'; index=i ,i++) {
				if(str[i] == '+') {
					key = true;
				}
				if(str[i] != '.' && !key) {
					res += str[i];
				}								
			}
			//cout << "@'s index: " << index << endl;
			res += '@'; // Bu satýrý silince % 96.66 oldu bu kadar farkettirirmi? SORULACAK!!!
			for(int i=index+2; i<str.size(); i++) { // @leet.. -> start from 'l'
				res += str[i];
			}
			return res;	    	
		}
		
		void printVector(vector<string>& emails) {
			for(int i=0; i<emails.size(); i++) {
				cout << emails[i] << endl;
			}
		}
};

int main(void) {
	vector<string> emails = {
		{"test.email+alex@leetcode.com"},
		{"test.e.mail+bob.cathy@leetcode.com"},
		{"testemail+david@lee.tcode.com"}
	};
	Solution obj;
	cout << obj.numUniqueEmails(emails);
	return 0;
}
