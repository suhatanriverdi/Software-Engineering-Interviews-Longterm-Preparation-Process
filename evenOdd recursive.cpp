//Question Description ---> We have an array filled with even and odd numbers like 1,3,5,2,4,7,6...
// Sort this array in order so that each even number be placed at right most of array and odds left most.
// INPUT ---> [1,2,3,4,5,6,7,8,9,0]
// OUTPUT ---> [2,4,6,8,0,1,3,5,7,9]
#include <iostream>
#include <vector>
using namespace std;

void helperSegregate(int arr[], int ret[], int current, int size, int front, int back) {
    if(current >= size) { // Base Condition
    	for(int i=0; i<size ;i++) {
			cout << ret[i] << " ";
		}
    	return;
	}
	
	if(arr[current] %2 == 0) {
		ret[front] = arr[current];
		front++;
	}
	
	else {
		ret[back] = arr[current];
		back--;
	}
	helperSegregate(arr, ret ,current+1, size, front, back);
}

void segregateEvenOdd() {
	int arr[10] = {1,2,3,4,5,6,7,8,9,0};
	int ret[10];
	helperSegregate(arr, ret, 0, 10, 0, 9);
}

int main(void) {
	segregateEvenOdd();		
	return 0;
}
