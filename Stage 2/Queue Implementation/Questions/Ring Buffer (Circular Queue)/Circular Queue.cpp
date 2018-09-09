#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
	private:
		vector<int> data;
		int front;
		int rear;
		int size;
			
	public:
	    /** Initialize your data structure here. Set the size of the queue to be k. */
	    MyCircularQueue(int k) {
	        data.resize(k); 
	        front = -1;
			rear = -1;
			size = k;
	    }
	    
	    /** Insert an element into the circular queue. Return true if the operation is successful. */
	    bool enQueue(int value) {
	    	
	        if(isFull()) {
	        	return false;
			}
	        
	        else {
	    
		    	if(isEmpty()) {  // There is a Queue but no elemenens inside it
					front = 0; //Head of Array	
		        }
		        
		        cout << "size:" << (rear+1)%size << endl;
		        rear = (rear+1)%size;
	        	data[rear]=value;
	        	return true;	
			}
	    }
	    
	    /** Delete an element from the circular queue. Return true if the operation is successful. */
	    bool deQueue() {
	    	
			if (isEmpty()) {
	            return false;
	        }
	        
	        if (front == rear) {
	            front = -1;
	            rear = -1;
	            return true;
	        }
	        
	        front = (front + 1) % size;
	        
	        return true;
	    }
	    
	    /** Get the front item from the queue. */
	    int Front() {
	        if(!isEmpty())
	        	return data[front];
	        return -1;
	    }
	    
	    /** Get the last item from the queue. */
	    int Rear() {
	        if(!isEmpty())
	        	return data[rear];
	        return -1;
	    }
	    
	    /** Checks whether the circular queue is empty or not. */
	    bool isEmpty() {
	        if(front == -1)
	        	return true;
	        return false;
	    }
	    
	    /** Checks whether the circular queue is full or not. */
	    bool isFull() {
	        if( (rear+1) % size == front)
	        	return true;	
	        
	        return false;
	    }

};

int main(void) {
	
	MyCircularQueue q(5);
    
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
	

	
	return 0;
}
