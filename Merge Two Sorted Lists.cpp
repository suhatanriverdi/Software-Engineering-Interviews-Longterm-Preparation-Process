// Question Link ---> https://leetcode.com/problems/merge-two-sorted-lists/
#include <iostream>
#include <set>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *gloList = NULL;
    multiset<int> orderedList;
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) {
            return l1?l1:l2;
        }
        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;
        while(ptr1 || ptr2) {
            if(ptr1) {                
                orderedList.insert(ptr1->val);
                ptr1 = ptr1->next;
            }
            if(ptr2) {                
                orderedList.insert(ptr2->val);
                ptr2 = ptr2->next;
            }
        }
        for(auto i : orderedList) {
            append(i);
        }
        return gloList;
    }
    void append(const int &val) {
        if (gloList == NULL) {
            gloList = new ListNode(val);
        }
        else {
            ListNode *walk = gloList;
            while (walk != NULL) {
                if (walk->next == NULL) {
                    walk->next = new ListNode(val);
                    break;
                }
                walk = walk->next;
            }
        }
    }
    void printList(ListNode *head) {
    	ListNode *walk = head;
    	while(walk != NULL) {
    		cout << walk->val << " ";
    		walk = walk->next;
		}
	}
};

int main(void) {
	Solution obj;
	ListNode *res;
	
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);
	
	ListNode *l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);
	
	res = obj.mergeTwoLists(l1, l2);
	obj.printList(res);
	return 0;
}
