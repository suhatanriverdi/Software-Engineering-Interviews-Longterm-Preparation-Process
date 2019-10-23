#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void evenOddN(int n) {
	cout << n << " ";
	if(n == 1) {
		return;
	}
	if(n%2 == 0) {	
		evenOddN(n/2);
	}
	if(n%2 != 0) {
		evenOddN((3*n)+1);
	}
}

int main(void) {
	int n;
	cin >> n;
	evenOddN(n);
	return 0;
}
