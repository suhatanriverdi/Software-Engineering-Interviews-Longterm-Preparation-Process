// Extract all digits from number and push one by one into a vector.
// Print them in reverse order :)
#include <iostream>
#include <vector>
using namespace std;

int main(void) {

	int num = 1453;
	int digit;
	vector<int> digits;
	
	while(num>0) {
		digit = num%10;
		cout << "Digit: " << digit << endl;
		digits.push_back(digit);
		num = num/10;
	}
	
	cout << endl << endl;
	for(int i=digits.size()-1; i>=0; i--) {
		cout << digits[i] << " ";
	}
	return 0;
}
