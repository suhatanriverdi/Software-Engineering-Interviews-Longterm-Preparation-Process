// Question Link ---> https://codeforces.com/problemset/problem/4/A
#include <iostream>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	// 0 <= n <= 100 .
	if(n%2 == 0 && n != 2) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
	return 0;
}
