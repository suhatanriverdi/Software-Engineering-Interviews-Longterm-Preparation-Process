#include <iostream>
#include <vector>
using namespace std;

void Iter_evenOddN(long long int n) {		
	while(n != 1) {	
		cout << n << " ";
		if(n%2 == 0) {
			n = (n/2);
			continue;
		}
		if(n%2 != 0) {
			n = ((3*n)+1);
		}
	}	
	cout << "1";
}

void Recur_evenOddN(long long int n) {
	cout << n << " ";
	if(n == 1) {
		return;
	}
	if(n%2 == 0) {	
		Recur_evenOddN(n/2);
	}
	if(n%2 != 0) {
		Recur_evenOddN((3*n)+1);
	}
}

int main(void) {
	long long int n;

	cout << "Enter n for ITERATIVE: ";
	cin >> n;
	Iter_evenOddN(n);

	
	return 0;
}
