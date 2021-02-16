//Question Description ---> If array has dublicated element return true like arr[2,3,4,5,5] ret true
//Given an array of n elements which contains elements from 0 to n-1,
//with any of these numbers appearing any number of times. 
#include <iostream>
#include <unordered_set>
using namespace std;

bool isDuplicatedSet(int array[]) {
  unordered_set<int> arr;
	for(int i=0; i<5; i++) {
		arr.insert(array[i]);
	}
	if(arr.size() == 5) {
		return false;
	}
	cout << "Duplicated Elements Found!";
	return true;
}

int main(void) {
	int array[5] = {1,2,3,4,2};
	isDuplicatedSet(array);
	return 0;
}
