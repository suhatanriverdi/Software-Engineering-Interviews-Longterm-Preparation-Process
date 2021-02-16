//Homework		.advance() Time Complexity, Manual Incrementation of Iterators
#include <iostream>
#include <vector>
#include <time.h> // time
#include <chrono>  // To measure time elapsed
using namespace std;
using namespace std::chrono;
	
void advanceTest(vector<int> &vec) {
	cout << "advance..." << endl;
	vector<int>::iterator it;
	it = vec.begin();
	advance(it, 99999999);
	cout << *it << endl;
}	

void manualTest(vector<int> &vec) {
	cout << "manual..." << endl;
	vector<int>::iterator it;
	it = vec.begin() + 99999999;
	cout << *it << endl;
	//it = vec.begin();
	//it += 99999999;
	//advance(it, lastProcessedChild[temp]); // Increment Iterator
}

int main(void) {
	
	vector<int> test(100000000);
	
	auto start = high_resolution_clock::now();
	advanceTest(test);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start); 
  	cout << "Advance elapsed time in microseconds: " << duration.count() << " ms";
	cout << endl << endl; 
	
	auto start1 = high_resolution_clock::now();
	manualTest(test);
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1); 
  	cout << "Manual elapsed time in microseconds: " << duration1.count() << " ms";
	cout << endl; 

	return 0;
}
