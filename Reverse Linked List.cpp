//Question Link ---> https://leetcode.com/problems/reverse-linked-list/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //  h -> 1 -> 2 -> 3 -> 4 -_ 
 //       ^    ^    ^
 //     prev  mid  next
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if(head == nullptr || head->next == nullptr){
            return head;
		}
            
        ListNode *first = head;
        ListNode *mid = head->next;
        ListNode *last;
		
        while(mid) { // We have at least two nodes
    		last = mid->next;
            mid->next = first;
            first = mid;
    		mid = last;
        }   
        
		head->next = nullptr;
        
        printList(first); // After Reversed
        
        return first;
    }
	
	void printList(ListNode* head) {
		ListNode *walk = head;
		while(walk) {
			cout << walk->val << " ";
			walk = walk->next;
		}
		cout << endl;
	}  
};


int main(void) {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	
	Solution obj;
	obj.printList(head); // Before Reversed
	obj.reverseList(head);
	return 0;
}
