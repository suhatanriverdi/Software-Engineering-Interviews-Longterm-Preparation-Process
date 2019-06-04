#include <iostream>
#include <vector>
#include <set>
#include <ctime>
#include <chrono>  // To measure time elapsed
using namespace std::chrono;
using namespace std;

typedef unsigned long long Type;
const Type MAX = 9999999;
const Type MIN = 1000000;

Type myRand(const Type Max, const Type Min = 0) {
	return rand()/(float)RAND_MAX * (Max-Min) + Min ;
}

long long TC_1st_Approach[1000000]; // TC is data
long long TC_2nd_Approach[1000000]; // TC is index
set<int> TC; // Set Data Structure

void insert_test_SET() {
	for(int i=0; i<1000000; i++) {
		TC.insert(myRand(MAX,MIN));
	}
}

void insert_test_1st_Approach() { // TC is data
	for(int i=0; i<1000000; i++) {
		TC_1st_Approach[i] = myRand(MAX,MIN);
	}
}

void search_on_1st_Approach() {
	for(int i=0; i<10000000; i++) {
		if(TC_1st_Approach[i] == 1023465) {
			cout << 1023465 << " found" << endl;
			break;
		}
	}
}

//void insert_test_2st_Approach() { // TC is index, to do that, we must allocate 
//	
//}

int main(void) {
	srand(unsigned(time(0)));
//	cout << "Initial set size: " << TC.size() << endl;
//	cout << "---> Time Test for Inserting On SET <---" << endl;
//	auto start = high_resolution_clock::now();
//	insert_test_SET(); // Inserting Random Numbers to SET 
//	auto stop = high_resolution_clock::now();
//	auto duration = duration_cast<milliseconds>(stop - start); 
//  	cout << endl << "Time elapsed in milliseconds: " << duration.count() << " ms";
//	cout << endl << endl << endl; 
//	cout << "Current set size: " << TC.size() << endl;
//	TC.insert(1023465);
//
////	// Iterate through all the elements in a set and display the value.
////	for (set<int>::iterator it=TC.begin(); it!=TC.end(); ++it) {
////		cout << ' ' << *it;
////	}
////	cout<<"\n";
//
//	// Searching Time Test
//	cout << "---> Time Test for Searching On SET <---" << endl << endl;
//	auto start_ = high_resolution_clock::now();
//
//	// Searching on SET
//	set<int>::iterator it = TC.find(1023465);
//	if(it != TC.end()) {
//		cout << 1023465 << " found" << endl;
//	}
//	else {
//		cout << "ELement not found" << endl;
//	}
//	
//	auto stop_ = high_resolution_clock::now();
//	auto duration_ = duration_cast<milliseconds>(stop_ - start_); 
//  	cout << endl << "Time elapsed in milliseconds: " << duration_.count() << " ms";
//	cout << endl << endl << endl;
	
	

//	cout << "---> Time Test for Inserting On 1st Approach <---" << endl;
//	auto start__ = high_resolution_clock::now();
//	insert_test_1st_Approach(); // Inserting Random Numbers to SET 
//	auto stop__ = high_resolution_clock::now();
//	auto duration__ = duration_cast<milliseconds>(stop__ - start__); 
//  	cout << endl << "Time elapsed in milliseconds: " << duration__.count() << " ms\n\n";



	cout << "---> Time Test for Searching On 1st Approach <---" << endl << endl;
	auto x = high_resolution_clock::now();
	search_on_1st_Approach();
	auto y = high_resolution_clock::now();
	auto d = duration_cast<milliseconds>(y - x); 
  	cout << endl << "Time elapsed in milliseconds: " << d.count() << " ms";
	
	return 0;
}
