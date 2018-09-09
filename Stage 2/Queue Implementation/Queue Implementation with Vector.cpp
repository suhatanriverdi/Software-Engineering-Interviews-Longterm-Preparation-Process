#include <iostream>
#include <vector>

using namespace std;

class Queue {
	private:
		vector<int> data; //Store Elements
		int p_start;
		
	public:
		Queue():p_start(0) {};
		
		bool enQueue(int x) {
			data.push_back(x);
			return true;
		}
		
		bool deQueue() {
			if(isEmpty()) {
				return false;
			}
			p_start++;
			return true;
		}
		
		int Front() {
			return data[p_start];
		}
		
		bool isEmpty() {
			return p_start >= data.size();
		}
};

int main(void) {
	
    Queue q;
    q.enQueue(5);
    q.enQueue(3);
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }
    q.deQueue();
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }
    q.deQueue();
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }
	return 0;
}
