//QUESTION Link ---> http://codeforces.com/contest/1/problem/A 
#include <iostream>    
using namespace std;

int main(void) {
	int m, n, a;
	long long width=0, height=0;
	cin >> m >> n >> a;
	
	width = (n + (a-1)) / a;
	height = (m + (a-1)) / a;
	
	cout << width*height << endl;	
	return 0;
}
