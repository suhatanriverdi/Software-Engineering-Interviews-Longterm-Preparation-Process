#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        if(n < 1) {
            return {};
        }
        vector<string> vec;
        for(int i=1; i<=n; i++) {
            if(i%15 == 0) {
                vec.push_back("FizzBuzz");
            }
            
            else if(i%3== 0) {
                vec.push_back("Fizz");
            }
            
            else if(i%5 == 0) {
                vec.push_back("Buzz");
            }
            
            else {
                vec.push_back(to_string(i));
            }
        }
        return vec;
    }
};

int main(void) {
	Solution obj;
	obj.fizzBuzz(15);
	return 0;
}
