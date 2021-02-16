//QUESTION Link ---> https://leetcode.com/problems/middle-of-the-linked-list/description/
#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Linkedlist {
	private:
		ListNode *head;
	public:
		Linkedlist():head(NULL){};
		
		void append(const int &value) {
			if(head==NULL) {
				head = new ListNode(value);
			}
			
			else {
				ListNode *walk = head;
				while(!walk==NULL) {
					if(walk->next == NULL) {
						walk->next = new ListNode(value);
						break;
					}
					walk = walk->next;
				}
			}
		}
		
		void printList() {
			ListNode *walk = head;
			while(!walk==NULL) {
					cout << " -> " << walk->val;
					walk = walk->next;
			}
		}
		
		ListNode* returnHead() {
			return head;	
		}
};

class Solution {
	public:
	    ListNode* middleNode(ListNode* head) {
	    	
	    	ListNode *front = head;
			ListNode *back = head;
	    	
	    	if(head->next == NULL) { //There is just one item in the list
	    		return head;
			}
			
			else {
				
				while(!front==NULL) {
				
					cout << "back: " << back->val << endl;
					cout << "front: " << front->val << endl;
					cout << "b-ptr: " << back << endl;
					cout << "f-ptr: " << front << endl;
				
					if(front->next == NULL) {
						cout << "middle: " << back->val << endl;
						return back;				
					}
					
					else if(front->next->next == NULL) {
						cout << "middle: " << back->val << endl;
						return back->next;				
					}

					back = back->next;
					front = front->next->next;
				}
			}
	    }
};

int main(void) {
	
	vector<int> a = {1,2,3,4,5,6};
	
	Solution obj;
	Linkedlist list;
	
	for(int i=0; i<a.size(); i++)
		list.append(a[i]);
	list.printList();
	
	obj.middleNode(list.returnHead()); //sends list
	
	return 0;
}
