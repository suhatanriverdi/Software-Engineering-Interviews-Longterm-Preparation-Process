#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>  // To measure time elapsed
using namespace std::chrono;
using namespace std;

void Iter_evenOddN(long long int n) {		
	while(n != 1) {	
		//cout << n << " ";
		if(n%2 == 0) {
			n = (n/2);
			continue;
		}
		if(n%2 != 0) {
			n = ((3*n)+1);
		}
	}	
	//cout << "1";
}

void Iter_evenOddN_noCont(long long int n) {		
	while(n != 1) {	
		//cout << n << " ";
		if(n%2 == 0) {
			n = (n/2);
		}
		else {
			n = ((3*n)+1);
		}
	}	
	//cout << "1";
}

void Recur_evenOddN(long long int n) {
//	cout << n << " ";
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
	cin >> n;
	// MEASURE TIME for RECURSIVE
  	auto start_ = high_resolution_clock::now();
  	for(int i=0; i<1000000; i++) {
		Iter_evenOddN(n);
	}
	auto stop_ = high_resolution_clock::now();
	auto duration_ = duration_cast<milliseconds>(stop_ - start_); 
  	cout << endl << "ITERATIVE Time elapsed in milliseconds: " << duration_.count() << " ms";
	cout << endl << endl;
	
	// MEASURE TIME for ITERATIVE
	auto start = high_resolution_clock::now();
	for(int i=0; i<1000000; i++) {
		Recur_evenOddN(n);
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start); 
  	cout << endl << "RECURSIVE Search Time elapsed in milliseconds: " << duration.count() << " ms";
	cout << endl << endl << endl; 
	
	
	// MEASURE TIME for ITERATIVE NO CONT
	auto start__ = high_resolution_clock::now();
	for(int i=0; i<1000000; i++) {
		Iter_evenOddN_noCont(n);
	}
	auto stop__ = high_resolution_clock::now();
	auto duration__ = duration_cast<milliseconds>(stop__ - start__); 
  	cout << endl << "ITERATIVE NO CONT Search Time elapsed in milliseconds: " << duration__.count() << " ms";
	cout << endl << endl << endl; 
	return 0;
}
