#include <iostream>
#include <set>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <chrono>  // To measure time elapsed
using namespace std;
using namespace std::chrono;

int first_Approach[1000000]; // TC is data

set<int> TC; // Set Data Structure

// Creates random number between 0 - 99999
int createRandomNum() {
	return rand()%1000000;
}

void insert_test_SET() {
	for(int i=0; i<1000000; i++) {
		TC.insert(createRandomNum());
	}
}


void insert_1st_Approach() { // TC is data
	for(int i=0; i<1000000; i++) {
		first_Approach[i] = createRandomNum();
	}
}

// Fills receiving vector with random numbers
void search_on_1st_Approach() {
	for(int i=0; i<1000000; i++) {
		if(first_Approach[i] == 1023465) {
			cout << 1023465 << " found" << endl;
			break;
		}
	}
}


int main(void) {
	
	cout << "Array size: 1000000" << endl;
	
	cout << "---> INSERTING On 1st Approach <---" << endl;
	auto start__ = high_resolution_clock::now();
	insert_1st_Approach(); // Inserting Random Numbers to SET 
	auto stop__ = high_resolution_clock::now();
	auto duration__ = duration_cast<milliseconds>(stop__ - start__); 
  	cout << "Time in milliseconds: " << duration__.count() << " ms\n\n";
	first_Approach[999999] = 1023465;
	
	cout << "---> SEARCHING On 1st Approach <---" << endl;
	auto start = high_resolution_clock::now();
	search_on_1st_Approach();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start); 
  	cout << "Time in microseconds: " << duration.count() << " ms";
	cout << endl << endl << endl; 
	
	
	cout << "Initial set size: " << TC.size() << endl;
	cout << "---> INSERTING On SET <---" << endl;
	auto start_ = high_resolution_clock::now();
	insert_test_SET(); // Inserting Random Numbers to SET 
	auto stop_ = high_resolution_clock::now();
	auto duration_ = duration_cast<milliseconds>(stop_ - start_); 
  	cout << "Time in milliseconds: " << duration_.count() << " ms";
	cout << endl; 
	cout << "Current set size: " << TC.size() << endl;
	TC.insert(1023465);
	cout << endl << endl;
//	// Iterate through all the elements in a set and display the value.
//	for (set<int>::iterator it=TC.begin(); it!=TC.end(); ++it) {
//		cout << ' ' << *it;
//	}
//	cout<<"\n";

	// Searching Time Test
	cout << "---> SEARCHING On SET <---" << endl;
	auto start_1 = high_resolution_clock::now();
	// Searching on SET
	set<int>::iterator it = TC.find(1023465);
	if(it != TC.end()) {
		cout << 1023465 << " found" << endl;
	}
	else {
		cout << "Element not found" << endl;
	}
	auto stop_1 = high_resolution_clock::now();
	auto duration_1 = duration_cast<milliseconds>(stop_1 - start_1); 
  	cout << "Time in milliseconds: " << duration_1.count() << " ms";
	cout << endl << endl << endl;
	
	return 0;
}
