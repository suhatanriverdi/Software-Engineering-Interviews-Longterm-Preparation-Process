#include <iostream>
#include <vector>
using namespace std;
 
void evenOddN(int n) {
	res:
	cout << n << " ";
	if(n == 1) {
		return;
	}
	if(n%2 == 0) {
		n = (n/2);
		goto res;
	}
	if(n%2 != 0) {
		n = ((3*n)+1);
		goto res;
	}
	goto res;
}

// BUNUN ÝLE YUKARDAKÝ GOTO lu OLANIN FARKINI SOR??
//void Iter_evenOddN(long long int n) {		
//	while(n != 1) {	
//		cout << n << " ";
//		if(n%2 == 0) {
//			n = (n/2);
//			continue;
//		}
//		if(n%2 != 0) {
//			n = ((3*n)+1);
//		}
//	}	
//	cout << "1";
//}

int main(void) {
	int n;
	cin >> n;
 	evenOddN(n);
}

