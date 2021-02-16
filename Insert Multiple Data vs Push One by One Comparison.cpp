//QUESTION Link ---> https://leetcode.com/problems/sort-array-by-parity/
#include <iostream>
#include <vector>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <chrono>  // To measure time elapsed
using namespace std;
using namespace std::chrono;

// Global Vectors, Create Vectors with initial size
vector<int> even;
vector<int> odd;

// Creates random number between 0 - 99999
int createRandomNum() {
	return rand()%10000;
}

// Fills receiving vector with random numbers
void fillVectorRandomly(vector<int> &vec) {
	for(int i=0; i<10000000; i++) {
		vec.push_back(createRandomNum());
	}
}

void printVector(vector<int> &vec) {
	for(int i=0; i<vec.size(); i++) {
		cout << vec[i] << endl;
	}
}

void test_insertOnMultiple() {
	even.insert(even.end(), odd.begin(), odd.end());
}

void test_OnebyOne() {
	for(int i=0; i<odd.size(); i++) {
		even.push_back(odd[i]);
	}
}

int main(void) {
	
	fillVectorRandomly(even);
	fillVectorRandomly(odd);

//	printVector(even);
//	printVector(odd);
	
	cout << "---> Time Test for Inserting On Multiple Values <---" << endl << endl;
	auto start = high_resolution_clock::now();
	test_insertOnMultiple();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start); 
  	cout << endl << "Time elapsed in microseconds: " << duration.count() << " ms";
	cout << endl << endl << endl; 
	
	cout << "---> Time Test for Pushing One by One <---" << endl << endl;
	auto start_ = high_resolution_clock::now();
	test_OnebyOne();
	auto stop_ = high_resolution_clock::now();
	auto duration_ = duration_cast<microseconds>(stop_ - start_); 
  	cout << endl << "Time elapsed in microseconds: " << duration_.count() << " ms";
	cout << endl << endl << endl; 

	return 0;
}
