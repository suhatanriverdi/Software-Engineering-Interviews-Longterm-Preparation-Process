//Question Description ---> We have an array filled with even and odd numbers like 1,3,5,2,4,7,6...
// Sort this array in order so that each even number be placed at right most of array and odds left most.
// INPUT ---> [1,2,3,4,5,6,7,8,9,0]
// OUTPUT ---> [2,4,6,8,0,1,3,5,7,9]
#include <iostream>
using namespace std;

void printArray(int arr[], const int &size) {
    for(int i=0; i<size ;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

void segregateEvenOdd(int arr[], int size, int current, int back) {
	if(current >= size || current >= back) {
		return;
	}
	
	if(arr[current] %2 == 0 && arr[back] %2 != 0) {
		swap(arr[current], arr[back]);
		back--;
		current++;
	}
	
	else if(arr[current] %2 == 0 && arr[back] %2 == 0) {
		back--;
	}
	
	else if(arr[current] %2 != 0) {
		current++;
	}
	
	segregateEvenOdd(arr, size, current, back);
}

int main(void) {
	int arr[10] = {1,2,3,4,5};
	printArray(arr, 5);
	segregateEvenOdd(arr, 5, 0, 4);		
	printArray(arr, 5);
	return 0;
}
