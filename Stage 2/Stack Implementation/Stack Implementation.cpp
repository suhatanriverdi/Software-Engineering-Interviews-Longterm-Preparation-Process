#include <iostream>
#include <vector>
using namespace std;

class Stack {
	private:
		vector<int> data; //Store Elements
		
	public:
		void push(int x) { //Insert an element into the stack.
			data.push_back(x);
		}
		
		int top() { //Get the top item, without deleting
			return data.back();
		}
		
		bool isEmpty() { //Checks whether the queue is empty or not
			return data.empty();
		}
		
		bool pop() { //Delete an element from the queue and return it
			if(isEmpty()) {
				return false;
			}
			data.pop_back();
			return true;
		}
};

int main(void) {	
	Stack s;
	
	s.push(1);
	s.push(2);
	s.push(3);
	
	for(int i=0; i<4; i++) {
		if(!s.isEmpty()) {
			cout << s.top() << endl;
		}
		cout << (s.pop() ? "true" : "false") << endl;
	}
	
	return 0;
}
