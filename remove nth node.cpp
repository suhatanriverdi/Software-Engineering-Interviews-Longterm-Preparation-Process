// Question Link ---> https://leetcode.com/problems/remove-nth-node-from-end-of-list/
/*
Given linked list: 1->2->3->4->5, and n = 2.
linked list becomes 1->2->3->5.
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) {
        	return head;
		}
		//helper(head, n);
		ListNode *slow = head;
		ListNode *fast = head;
		int slow_cnt = 1, fast_cnt = 1;
		cout << "slow: " << slow->val;
		cout << " fast: " << fast->val << " s_cnt: " << slow_cnt << " f_cnt: " << fast_cnt << endl;
    	while(fast->next != NULL && fast->next->next != NULL) {
    		slow = slow->next;
    		fast = fast->next->next;
    		slow_cnt++;
    		fast_cnt += 2;
    		cout << "slow: " << slow->val;
    		cout << " fast: " << fast->val << " s_cnt: " << slow_cnt << " f_cnt: " << fast_cnt << endl;		
		}
		if(fast->next != NULL) {
			fast_cnt++;
			fast = fast->next;
		}
		cout << "last f: " << fast->val << endl;
		cout << "List Length: " << fast_cnt << endl;
		cout << "Slow Count(some-mid): " << slow_cnt << endl;
		int nodeRemoved = fast_cnt-n+1;
		cout << "Node to be deleted: " << nodeRemoved << "th" << endl;
		// The node to be removed can be -> head -> last -> in the middle somewhere
		// If Head
		if(nodeRemoved == 1) {
			cout << "Removed: " << head->val << endl;
			// Removing
			ListNode *rem = head;
			head = head->next;
			cout << "new Head: " << head->val << endl;
			delete rem;
		}
		// If Not Head, Mid or Last
		else {		
			// If Middle Somewhere or The Last
			// If Between Slow and Fast
			if(nodeRemoved >= slow_cnt && nodeRemoved <= fast_cnt) {
				while(slow_cnt+1 != nodeRemoved) {
					// We need to find the previous node
					slow_cnt++;
					slow = slow->next;
				}
				cout << "Removed: " << slow->next->val << endl;
				// Removing
				ListNode *rem = slow->next;
				slow->next = slow->next->next;;
				free(rem);
			}
			
			// If Between Head and Slow
			if(nodeRemoved >= 1 && nodeRemoved <= slow_cnt) {
				int head_cnt = 1;
				ListNode *walk = head;
				while(head_cnt+1 != nodeRemoved) {
					// We need to find the previous node
					head_cnt++;
					walk = walk->next;
				}
				cout << "Removed: " << walk->next->val << endl;
				// Removing
				ListNode *rem = walk->next;
				walk->next = walk->next->next;
				free(rem);
			}
		}
		
		return head;
    } 
    
    //Recursive Attempt
    void helper(ListNode* current, int n) {
    	if(current == NULL) {
        	return;
		}
 		helper(current->next, n);
		cout << current->val << " ";
	}
    
    void printList(ListNode *head) {
    	ListNode *walk = head;
    	while(walk != NULL) {
    		cout << walk->val;
    		walk = walk->next;
    		if(walk != NULL) {
    			cout << "->";	
			}
		}
		cout << endl;
	}
};

int main(void) {
    ListNode *node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(3);
    node->next->next->next = new ListNode(4);
    node->next->next->next->next = new ListNode(5);
//    node->next->next->next->next->next = new ListNode(6);
    Solution obj;
    obj.printList(node);
    node = obj.removeNthFromEnd(node, 5);
    obj.printList(node);
    return 0;
}
