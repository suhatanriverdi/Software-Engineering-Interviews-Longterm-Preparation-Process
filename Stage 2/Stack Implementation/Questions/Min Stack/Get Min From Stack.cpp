#include <iostream>
#include <stack>

using namespace std;

class MinStack {
	
	private:
	    stack<int> s1;
	    stack<int> s2;
	    
	public:
	    void push(int x) {
		    s1.push(x);
		    if (s2.empty() || x <= getMin())  s2.push(x);	    
	    }
	    
	    void pop() {
		    if (s1.top() == getMin())
				s2.pop();
		    s1.pop();
	    }
	    
	    int top() {
		    return s1.top();
	    }
	    
	    int getMin() {
		    return s2.top();
	    }
};

int main(void) {
	
	MinStack obj;
	
	obj.push(-2);
	obj.push(0);
	obj.push(-3);
	
	cout << obj.getMin() << endl;
	
	obj.pop();
	
	cout << obj.top() << endl;
	
	cout << obj.getMin() << endl;
	
	return 0;
}
