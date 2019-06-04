#include <iostream>
using namespace std;

//index 1 2 3 4 5 6  7  8 ...
//fib   1 1 2 3 5 8 13 21 ...

//			  fib(5) = 5
//		    /	    \
//	      (4)=3     (3)=2
//		/	 \      /  \
//	  (3)=2  (2)   (2) (1)
//	  /	\     1    1   1
//	(2) (1)  
//	 1   1   
// 
//

// Tail Recursive
long int tailRecursive(int n, int a = 0, int b = 1) {
	cout << "a: " << a << "\t b: " << b << endl;
	if(n == 0) {
		return a;
	}
	if(n == 1) {
		return b;
	}
	return tailRecursive(n-1, b, a+b);
}

// Iterative
long int Iterativefib(int n) {
	int a = 0, b=1, c;
	if(n == 0) {
		return 0;
	}
	for(int i=2; i<=n; i++) {
		cout << "a: " << a << "\t b: " << b << endl;
		c=a+b;
		a=b;
		b=c;
	}
	return b;
}

// Using Memorising
long RecMemorisingFib(int n) {
	int backup[n+2];
	backup[0] = 0;
	backup[1] = 1;
	for(int i=2; i<=n; i++) {
		backup[i] = backup[i-1] + backup[i-2];	
	}
	return backup[n];
}

// Recursively
long Recursivefib(int n) {
	if(n == 1 || n == 2) {
		return 1;
	}
	return Recursivefib((n-1)+(n-2));
}

int main(void) {
	int n;
	cin >> n;
	cout << "Recursive Memorising: " << n << ": " << RecMemorisingFib(n) << endl;
	//cout << "Tail Recursive: " << n << ": " << tailRecursive(n) << endl;
	//cout << "Recursive Fibonacci: " << n << ": " << Recursivefib(n) << endl;
	//cout << "Iterative Fibonacci for " << n << " is: " << Iterativefib(n) << endl;
	return 0;
}
