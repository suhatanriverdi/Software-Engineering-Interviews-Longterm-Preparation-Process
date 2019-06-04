// Question Link ---> https://codeforces.com/contest/71/problem/A
#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	string s[n];
	
	for(int i=0; i<n; i++) {
		cin >> s[i];
	}
	
	for(int i=0; i<n; i++) {
		if(s[i].size()-1 >= 10) {
			cout << s[i].at(0) << s[i].size()-2 << s[i].at(s[i].size()-1) << endl;
		}
		else {
			cout << s[i] << endl;
		}
	}
	
	return 0;
}
