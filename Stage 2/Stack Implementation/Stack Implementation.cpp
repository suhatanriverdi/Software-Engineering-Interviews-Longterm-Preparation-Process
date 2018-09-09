#include <iostream>
#include <vector>

using namespace std;

class Stack {
	private:
		vector<int> data; //Store Elements
		
	public:
		//Insert an element into the stack.
		void push(int x) {
			data.push_back(x);
		}
		
		//Get the top item, without deleting
		int top() {
			return data.back();
		}
		
		//Checks whether the queue is empty or not
		bool isEmpty() {
			return data.empty();
		}
		
		//Delete an element from the queue and return it
		bool pop() {
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
