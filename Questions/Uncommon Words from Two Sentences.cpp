//QUESTION Link ---> https://leetcode.com/problems/uncommon-words-from-two-sentences/
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
    	vector<string> ret; // Result
    	vector<pair<string, int>> walk;
    	string temp;
    	istringstream iss(A + " " + B);
    	while(iss >> temp) {
    		walk.push_back(make_pair(temp, 0));
		}

		for(int i=0; i<walk.size(); i++) {
			isRepeated(walk, walk[i].first);
		}
		
		for(int i=0; i<walk.size(); i++) {
			if(walk[i].second == 1) {
				ret.push_back(walk[i].first);
			}
		}

    	return ret;
    }
    
    void isRepeated(vector<pair<string, int>> &sentence, string word) {
		for(int i=0; i<sentence.size(); i++) {
			if(word == sentence[i].first) {
				sentence[i].second++;
			}
		}
	}
};

int main(void) {
	string A = "this apple is sweet"; 
	string B = "this apple is sour";
	vector<string> ret;
	Solution ans;
	ret = ans.uncommonFromSentences(A, B);
	cout << endl << endl;
	for(int i=0; i<ret.size(); i++) {
		cout << ret[i];
	}
	return 0;
}
