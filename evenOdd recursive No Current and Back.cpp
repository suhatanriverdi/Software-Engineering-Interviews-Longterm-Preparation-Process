//Question Description ---> We have an array filled with even and odd numbers like 1,3,5,2,4,7,6...
// Sort this array in order so that each even number be placed at right most of array and odds left most.
// INPUT ---> [1,2,3,4,5,6,7,8,9,0]
// OUTPUT ---> [2,4,6,8,0,1,3,5,7,9]
#include <iostream>
using namespace std;

void printArray(int arr[], int current, const int &size) {
	if(current >= size) {
		cout << endl;
		return;
	}
		cout << arr[current] << " ";
		printArray(arr, current+1 ,size);
}

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

// *arr => First Value = 1 
// *(arr+3) => Fourth Value = 4
// arr => 0x6ffe20 (Address)
// arr[size-1] => 5 (Value)
// &array[0] => Element 0 is at address: 0041FE9C
void segregateEvenOdd(int arr[], int size) {
	if( arr >= &(arr[size]) ) {
		return;
	}
	
	if( *arr %2 == 0 && *(arr+size-1) %2 != 0) {
		swap(*arr, *(arr+size-1));
		size--;
		segregateEvenOdd(arr+1, size);
	}
	
	else if(*arr %2 == 0 && *(arr+size-1) %2 == 0) {
		size--;
		segregateEvenOdd(arr, size);
	}
	
	else if(*arr %2 != 0) {
		segregateEvenOdd(arr+1, size);
	}
}

int main(void) {
	int arr[10] = {1,2,3,4,5};
	printArray(arr, 0, 5);
	segregateEvenOdd(arr, 5);		
	printArray(arr, 0, 5);
	return 0;
}
